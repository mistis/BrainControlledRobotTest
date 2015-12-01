//
//  CommandPacketGeneratorTest.cpp
//  BrainControlledRobotTest
//
//  Created by misti stevens on 11/30/15.
//  Copyright (c) 2015 Misti Stevens. All rights reserved.
//

#include "gmock/gmock.h"
#include "CommandDefinitions.h"
#include "Commands.h"
#include "CommandPacketGenerator.h"


class CommandMock : public Commands {
public:
    
    CommandMock() {}
    
    MOCK_METHOD0(moveLeft, void(void));
    MOCK_METHOD0(moveRight, void(void));
    MOCK_METHOD0(spin, void(void));
    MOCK_METHOD0(moveForward, void(void));
    MOCK_METHOD0(moveBackward, void(void));
    MOCK_METHOD0(stopMoving, void(void));
    MOCK_METHOD0(shoot, void(void));
};

using ::testing::AtLeast;

TEST(CommandPacketGeneratorTest, Stop) {
    CommandMock cmd;
    
    EXPECT_CALL(cmd, stopMoving())
        .Times(1);
    
    CommandPacketGenerator cmdGen(&cmd);
    cmdGen.SendCommandPacket(mHold);
}

TEST(CommandPacketGeneratorTest, Left) {
    CommandMock cmd;
    
    EXPECT_CALL(cmd, moveLeft())
        .Times(1);
    
    CommandPacketGenerator cmdGen(&cmd);
    cmdGen.SendCommandPacket(mLeft);
}

TEST(CommandPacketGeneratorTest, Right) {
    CommandMock cmd;
    
    EXPECT_CALL(cmd, moveRight())
        .Times(1);
    
    CommandPacketGenerator cmdGen(&cmd);
    cmdGen.SendCommandPacket(mRight);
}

TEST(CommandPacketGeneratorTest, Spin) {
    CommandMock cmd;
    
    EXPECT_CALL(cmd, spin())
        .Times(1);
    
    CommandPacketGenerator cmdGen(&cmd);
    cmdGen.SendCommandPacket(mSpin);
}

TEST(CommandPacketGeneratorTest, Forward) {
    CommandMock cmd;
    
    EXPECT_CALL(cmd, moveForward())
        .Times(1);
    
    CommandPacketGenerator cmdGen(&cmd);
    cmdGen.SendCommandPacket(mForward);
}

TEST(CommandPacketGeneratorTest, Backward) {
    CommandMock cmd;
    
    EXPECT_CALL(cmd, moveBackward())
        .Times(1);
    
    CommandPacketGenerator cmdGen(&cmd);
    cmdGen.SendCommandPacket(mBackward);
}

TEST(CommandPacketGeneratorTest, Shoot) {
    CommandMock cmd;
    
    EXPECT_CALL(cmd, shoot())
        .Times(1);
    
    CommandPacketGenerator cmdGen(&cmd);
    cmdGen.SendCommandPacket(mShoot);
}
