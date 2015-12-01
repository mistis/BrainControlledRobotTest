//
//  CommandPacketGeneratorTest.cpp
//  BrainControlledRobotTest
//
//  Created by misti stevens on 11/30/15.
//  Copyright (c) 2015 Misti Stevens. All rights reserved.
//

#include "gmock/gmock.h"
#include "Commands.h"


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
