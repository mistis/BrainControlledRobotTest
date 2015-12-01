//
//  ComandPacketGenerator.cpp
//  
//
//  Created by misti stevens on 10/16/15.
//
//

#include "CommandPacketGenerator.h"
#include "CommandDefinitions.h"

CommandPacketGenerator::CommandPacketGenerator(Commands* cmdGen) :
    mCommandHandler(cmdGen)
{

}

CommandPacketGenerator::~CommandPacketGenerator()
{
}


void CommandPacketGenerator::SendCommandPacket(const int commandNum)
{
    switch (commandNum) {
        case mHold:
            mCommandHandler->stopMoving();
            break;

        case mForward:
            mCommandHandler->moveForward();
            break;

        case mBackward:
            mCommandHandler->moveBackward();
            break;

        case mLeft:
            mCommandHandler->moveLeft();
            break;

        case mRight:
            mCommandHandler->moveRight();
            break;
            
        case mSpin:
            mCommandHandler->spin();
            break;

        case mShoot:
            mCommandHandler->shoot();
            break;

        default:
            break;
    }
}
