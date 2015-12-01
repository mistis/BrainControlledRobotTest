//
//  NXTCommands.h
//
//
//  Created by Chris Frazier
//
//

#ifndef NXTCommands_h
#define NXTCommands_h

#include "Commands.h"
#define PACKET_SIZE 14
#define BAUD_RATE 38400

#if ARDUINO_BUILD
    #include <Arduino.h>
    #include <SoftwareSerial.h>
#else
    #include "TestLib.h"
#endif



class NXTCommands : public Commands {
    
public:
    
    NXTCommands();

    virtual void moveLeft();
    virtual void moveRight();
    virtual void spin();
    virtual void moveForward();
    virtual void moveBackward();
    virtual void stopMoving();
    virtual void shoot();

    void setSpeed(const int speed);
    void move(byte speed, bool spin=false);
    void playTone(byte,byte);
    
private:
    
    SoftwareSerial *BTSerial;
    
    byte _speed;
    
    byte _frequencyLSB;
    byte _frequencyMSB;
    byte _durationLSB;
    byte _durationMSB;
    
    int _delayTime;
    
    byte _leftMotor[PACKET_SIZE] = { 0x0C, 0x00, 0x80, 0x04, 0x02, 0x64, 0x07, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00 };
    byte _rightMotor[PACKET_SIZE] = { 0x0C, 0x00, 0x80, 0x04, 0x01, 0x64, 0x07, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00 };
    byte _shootMotor[PACKET_SIZE] = { 0x0C, 0x00, 0x80, 0x04, 0x00, 0x00, 0x07, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00 };
    byte _tone[PACKET_SIZE] = { 0x06, 0x00, 0x80, 0x03, 0x0B, 0x02, 0xF4, 0x01, 0, 0, 0, 0, 0, 0 };
    
};

#endif
