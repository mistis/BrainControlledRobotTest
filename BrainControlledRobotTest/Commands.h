//
//  Commands.h
//  BrainControlledRobotTest
//
//  Created by misti stevens on 11/30/15.
//  Copyright (c) 2015 Misti Stevens. All rights reserved.
//

#ifndef __BrainControlledRobotTest__Commands__
#define __BrainControlledRobotTest__Commands__

class Commands {
    
public:
    
    virtual ~Commands() {}
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void spin() = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual void stopMoving() = 0;
    virtual void shoot() = 0;
};

#endif 