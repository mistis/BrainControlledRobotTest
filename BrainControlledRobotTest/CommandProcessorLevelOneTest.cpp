//
//  CommandProcessorLevelOneTest.cpp
//  BrainControlledRobotTest
//
//  Created by misti stevens on 11/30/15.
//  Copyright (c) 2015 Misti Stevens. All rights reserved.
//

#include "gtest/gtest.h"
#include "CommandProcessorLevelOne.h"
#include "CommandDefinitions.h"

TEST(CommandProcessorLevelOneTest, Stop_Mid_Boundary)
{
    const int samplesToProcess = 1;
    CommandProcessorLevelOne processor(samplesToProcess);
    
    // ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
    const int attentionVal  = 0;
    const int meditationVal = 0;
    const int sample        = 0;

    EXPECT_LT(sample, samplesToProcess);
    EXPECT_EQ(mHold, processor.ProcessCommand(attentionVal, meditationVal, sample));
}

TEST(CommandProcessorLevelOneTest, Stop_High_Boundary)
{
    const int samplesToProcess = 1;
    CommandProcessorLevelOne processor(samplesToProcess);
    
    // ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
    const int attentionVal  = 49;
    const int meditationVal = 0;
    const int sample        = 0;
    
    EXPECT_LT(sample, samplesToProcess);
    EXPECT_EQ(mHold, processor.ProcessCommand(attentionVal, meditationVal, sample));
}

TEST(CommandProcessorLevelOneTest, Stop_Low_Boundary)
{
    const int samplesToProcess = 1;
    CommandProcessorLevelOne processor(samplesToProcess);
    
    // ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
    const int attentionVal  = 0;
    const int meditationVal = 49;
    const int sample        = 0;
    
    EXPECT_LT(sample, samplesToProcess);
    EXPECT_EQ(mHold, processor.ProcessCommand(attentionVal, meditationVal, sample));
}

TEST(CommandProcessorLevelOneTest, Stop_EQ_Vals)
{
    const int samplesToProcess = 1;
    CommandProcessorLevelOne processor(samplesToProcess);
    
    // ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
    // If difference > 40, we shoot
    const int attentionVal  = 50;
    const int meditationVal = 50;
    const int sample        = 0;
    
    EXPECT_LT(sample, samplesToProcess);
    EXPECT_EQ(mHold, processor.ProcessCommand(attentionVal, meditationVal, sample));
}

TEST(CommandProcessorLevelOneTest, Forward_Mid)
{
    const int samplesToProcess = 1;
    CommandProcessorLevelOne processor(samplesToProcess);
    
    // ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
    // If difference > 40, we shoot
    const int attentionVal  = 60;
    const int meditationVal = 30;
    const int sample        = 0;
    
    EXPECT_LT(sample, samplesToProcess);
    EXPECT_EQ(mForward, processor.ProcessCommand(attentionVal, meditationVal, sample));
}

TEST(CommandProcessorLevelOneTest, Forward_Low_Boundary)
{
    const int samplesToProcess = 1;
    CommandProcessorLevelOne processor(samplesToProcess);
    
    // ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
    // If difference > 40, we shoot
    const int attentionVal  = 51;
    const int meditationVal = 50;
    const int sample        = 0;
    
    EXPECT_LT(sample, samplesToProcess);
    EXPECT_EQ(mForward, processor.ProcessCommand(attentionVal, meditationVal, sample));
}

TEST(CommandProcessorLevelOneTest, Forward_High_Boundary)
{
    const int samplesToProcess = 1;
    CommandProcessorLevelOne processor(samplesToProcess);
    
    // ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
    // If difference > 40, we shoot
    const int attentionVal  = 51;
    const int meditationVal = 12;
    const int sample        = 0;
    
    EXPECT_LT(sample, samplesToProcess);
    EXPECT_EQ(mForward, processor.ProcessCommand(attentionVal, meditationVal, sample));
}

TEST(CommandProcessorLevelOneTest, Shoot)
{
    const int samplesToProcess = 1;
    CommandProcessorLevelOne processor(samplesToProcess);
    
    // ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
    // If difference > 40, we shoot
    const int attentionVal  = 51;
    const int meditationVal = 11;
    const int sample        = 0;
    
    EXPECT_LT(sample, samplesToProcess);
    EXPECT_EQ(mForward, processor.ProcessCommand(attentionVal, meditationVal, sample));
}

TEST(CommandProcessorLevelOneTest, Spin)
{
    const int samplesToProcess = 1;
    CommandProcessorLevelOne processor(samplesToProcess);
    
    // ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
    // If difference > 40, we shoot
    const int attentionVal  = 30;
    const int meditationVal = 60;
    const int sample        = 0;
    
    EXPECT_LT(sample, samplesToProcess);
    EXPECT_EQ(mSpin, processor.ProcessCommand(attentionVal, meditationVal, sample));
}