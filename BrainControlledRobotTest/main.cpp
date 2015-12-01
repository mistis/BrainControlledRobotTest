// Copyright 2009 Google Inc. All Rights Reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: vladl@google.com (Vlad Losev)

// This sample shows how to use Google Test listener API to implement
// an alternative console output and how to use the UnitTest reflection API
// to enumerate test cases and tests and to inspect their results.

#include <stdio.h>

#include "gtest/gtest.h"

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

namespace {
    
    // Provides alternative output mode which produces minimal amount of
    // information about tests.
    class TersePrinter : public EmptyTestEventListener {
    private:
        // Called before any test activity starts.
        virtual void OnTestProgramStart(const UnitTest& /* unit_test */) {}
        
        // Called after all test activities have ended.
        virtual void OnTestProgramEnd(const UnitTest& unit_test) {
            fprintf(stdout, "Tests Passed: %d/%d ",
                    unit_test.successful_test_count(),
                    unit_test.total_test_count()
                    );
            if (unit_test.failed_test_count()) {
                fprintf(stdout, "Failed: %d/%d\n",
                        unit_test.failed_test_count(),
                        unit_test.total_test_count()
                        );
            } else {
                fprintf(stdout, "\n");
            }
            
            if (unit_test.disabled_test_count()) {
                fprintf(stdout, "Disabled Tests: %d/%d\n",
                        unit_test.disabled_test_count(),
                        unit_test.total_test_count()
                        );
            }
            fprintf(stdout, "Time to run tests: %lld ms\n", unit_test.elapsed_time());
            fflush(stdout);
        }
        
        const TestInfo *currentTest;
        // Called before a test starts.
        virtual void OnTestStart(const TestInfo& test_info) {
            currentTest = &test_info;
        }
        
        // Called after a failed assertion or a SUCCEED() invocation.
        virtual void OnTestPartResult(const TestPartResult& test_part_result) {
            if (test_part_result.failed()) {
                std::string summary(test_part_result.summary());
                for (int i=0; i < summary.length(); i++) {
                    if (summary[i] == '\n') {
                        summary[i] = ' ';
                    }
                }
                fprintf(stdout, "%s:%d: FAILED In Test [%s.%s]\n\t%s\n",
                        test_part_result.file_name(), test_part_result.line_number(),
                        currentTest->test_case_name(), currentTest->name(),
                        summary.c_str());
                fflush(stdout);
            }
        }
        
        // Called after a test ends.
        virtual void OnTestEnd(const TestInfo& test_info) {
            if (0) {
                fprintf(stdout, "*** Test %s.%s ending.\n",
                        test_info.test_case_name(),
                        test_info.name());
                fflush(stdout);
            }
        }
    };  // class TersePrinter
    
}  // namespace

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    
    bool terse_output = true;
    
    printf("\n");
    
    if (argc > 1 && strcmp(argv[1], "--no_terse_output") == 0 )
        terse_output = false;
    else if (!terse_output)
        printf("%s\n", "Run this program with --terse_output to change the way "
               "it prints its output.");
    
    UnitTest& unit_test = *UnitTest::GetInstance();
    
    // If we are given the --terse_output command line flag, suppresses the
    // standard output and attaches own result printer.
    if (terse_output) {
        TestEventListeners& listeners = unit_test.listeners();
        
        // Removes the default console output listener from the list so it will
        // not receive events from Google Test and won't print any output. Since
        // this operation transfers ownership of the listener to the caller we
        // have to delete it as well.
        delete listeners.Release(listeners.default_result_printer());
        
        // Adds the custom output listener to the list. It will now receive
        // events from Google Test and print the alternative output. We don't
        // have to worry about deleting it since Google Test assumes ownership
        // over it after adding it to the list.
        listeners.Append(new TersePrinter);
    }
    
    int ret_val = RUN_ALL_TESTS();
    
    // This is an example of using the UnitTest reflection API to inspect test
    // results. Here we discount failures from the tests we expected to fail.
    int unexpectedly_failed_tests = 0;
    for (int i = 0; i < unit_test.total_test_case_count(); ++i) {
        const TestCase& test_case = *unit_test.GetTestCase(i);
        for (int j = 0; j < test_case.total_test_count(); ++j) {
            const TestInfo& test_info = *test_case.GetTestInfo(j);
            // Counts failed tests that were not meant to fail (those without
            // 'Fails' in the name).
            if (test_info.result()->Failed() &&
                strcmp(test_info.name(), "Fails") != 0) {
                unexpectedly_failed_tests++;
            }
        }
    }
    
    // Test that were meant to fail should not affect the test program outcome.
    if (unexpectedly_failed_tests == 0)
        ret_val = 0;
    
    return ret_val;
}
