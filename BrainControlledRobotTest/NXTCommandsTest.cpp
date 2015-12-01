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
*/

TEST(NXTCommands, Stop)
{
    NXTCommands nxtCmd;

}
