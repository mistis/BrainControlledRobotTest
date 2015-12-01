//
//  TestLib.h
//  BrainControlledRobotTest
//
//  Created by misti stevens on 11/30/15.
//  Copyright (c) 2015 Misti Stevens. All rights reserved.
//

#ifndef BrainControlledRobotTest_TestLib_h
#define BrainControlledRobotTest_TestLib_h

#define byte unsigned char


void delay(int delayTime);

struct SoftwareSerial {
    
    SoftwareSerial(int tx, int rx)
    {
    
    }
    
    void begin(int baudRate)
    {
    }
    
    void write(byte* message, int packetSize)
    {
    
    }
};


#endif
