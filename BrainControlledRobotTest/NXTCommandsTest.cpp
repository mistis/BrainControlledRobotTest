//
//  NXTCommandsTest.cpp
//  BrainControlledRobotTest
//
//  Created by misti stevens on 12/1/15.
//  Copyright (c) 2015 Misti Stevens. All rights reserved.
//

#include "gtest/gtest.h"
#include "NXTCommands.h"

unsigned char mLeftMotor[PACKET_SIZE]  = { 0x0C, 0x00, 0x80, 0x04, 0x02, 0x64, 0x07, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00 };
unsigned char mRightMotor[PACKET_SIZE] = { 0x0C, 0x00, 0x80, 0x04, 0x01, 0x64, 0x07, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00 };
unsigned char mShootMotor[PACKET_SIZE] = { 0x0C, 0x00, 0x80, 0x04, 0x00, 0x00, 0x07, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00 };
unsigned char mTone[PACKET_SIZE]       = { 0x06, 0x00, 0x80, 0x03, 0x0B, 0x02, 0xF4, 0x01, 0, 0, 0, 0, 0, 0 };

/*
 virtual void stopMoving();
 virtual void moveLeft();
 virtual void moveRight();
 virtual void spin();
 virtual void moveForward();
 virtual void moveBackward();
 virtual void shoot();
 
 void setSpeed(const int speed);
 void move(byte speed, bool spin=false);
 void playTone(byte,byte);
 
 // Testing Routines
 byte getLeftMotorPacket(int byteIndex);
 byte getRightMotorPacket(int byteIndex);
 byte getShootMotorPacket(int byteIndex);
 byte getTonePacket(int byteIndex);
 byte getSpeed();

*/

TEST(NXTCommands, Initializtion)
{
    NXTCommands nxtCmd;
    
    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
        EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
        EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
        EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
    }
}

TEST(NXTCommands, Stop)
{
    NXTCommands nxtCmd;
}

TEST(NXTCommands, Left)
{
    NXTCommands nxtCmd;
    
    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
        EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
        EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
        EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
    }
    
    nxtCmd.moveLeft();
    
    // Never implmented - expect no change
    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
        EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
        EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
        EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
    }

}

TEST(NXTCommands, Right)
{
    NXTCommands nxtCmd;
    
    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
        EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
        EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
        EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
    }
    
    nxtCmd.moveRight();
    
    // Never implmented - expect no change
    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
        EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
        EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
        EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
    }
}

/*
    _leftMotor[5]  = spin ? -1*speed/4 : speed/2;
	_rightMotor[5] = spin ? speed/4 : speed/2;
*/

TEST(NXTCommands, Forward)
{
    NXTCommands nxtCmd;
    
    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
        EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
        EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
        EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
    }

    nxtCmd.moveForward();
    
    unsigned char speed = nxtCmd.getSpeed() / 2;

    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        if (i == 5) {
            EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     speed);
            EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    speed);
            EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
            EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
        } else {
            EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
            EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
            EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
            EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
        }
    }

}

/*
 _leftMotor[5]  = spin ? -1*speed/4 : speed/2;
	_rightMotor[5] = spin ? speed/4 : speed/2;
 */

TEST(NXTCommands, Backward)
{
    NXTCommands nxtCmd;
    
    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
        EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
        EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
        EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
    }

    nxtCmd.moveBackward();
    
    unsigned char speed = nxtCmd.getSpeed() * -1;
    speed = speed / 2;
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        if (i == 5) {
            EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     speed);
            EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    speed);
            EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
            EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
        } else {
            EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
            EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
            EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
            EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
        }
    }
}

/*
 _leftMotor[5]  = spin ? -1*speed/4 : speed/2;
	_rightMotor[5] = spin ? speed/4 : speed/2;
 */

TEST(NXTCommands, Spin)
{
    NXTCommands nxtCmd;
    
    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
        EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
        EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
        EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
    }
    
    nxtCmd.spin();
    
    unsigned char rightSpeed = nxtCmd.getSpeed() / 4;
    unsigned char leftSpeed = -1 * nxtCmd.getSpeed() / 4 ;
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        if (i == 5) {
            EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     leftSpeed);
            EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    rightSpeed);
            EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
            EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
        } else {
            EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
            EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
            EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
            EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
        }
    }

}

TEST(NXTCommands, Shoot)
{
    NXTCommands nxtCmd;
    
    
    EXPECT_EQ(nxtCmd.getSpeed(), 0x64);
    
    for (int i = 0; i < PACKET_SIZE; ++i) {
        EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
        EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
        EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
        EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
    }
    
    nxtCmd.shoot();
    
    // Shoot is instantaneous - expect no change in shoot, forward motor in motion
    // but should update later for better testing of setting shoot motor
    
    // TODO: Maybe we shouldn't stop after we shoot?
    
    unsigned char speed = '\0';

    for (int i = 0; i < PACKET_SIZE; ++i) {
        if (i == 5) {
            EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     speed);
            EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    speed);
            EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
            EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
        } else {
            EXPECT_EQ(nxtCmd.getLeftMotorPacket(i),     mLeftMotor[i]);
            EXPECT_EQ(nxtCmd.getRightMotorPacket(i),    mRightMotor[i]);
            EXPECT_EQ(nxtCmd.getShootMotorPacket(i),    mShootMotor[i]);
            EXPECT_EQ(nxtCmd.getTonePacket(i),          mTone[i]);
        }
    }
}


