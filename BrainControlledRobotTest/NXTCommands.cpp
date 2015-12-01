//
//  NXTCommands.cpp
//
//
//  Created by Chris Frazier
//
//

#include "NXTCommands.h"

NXTCommands::NXTCommands() :
    _speed(0x64)
  , _frequencyLSB(0x0B)
  , _frequencyMSB(0x02)
  , _durationLSB(0xF4)
  , _durationMSB(0x01)
  , _delayTime(100)
{
	BTSerial = new SoftwareSerial(10,11); //RX,TX pins
	BTSerial->begin(BAUD_RATE);
}

void NXTCommands::setSpeed(const int speed)
{
  _speed = speed;
}

 void NXTCommands::move(byte speed, bool spin)
{   
	_leftMotor[5]  = spin ? -1*speed/4 : speed/2;
	_rightMotor[5] = spin ? speed/4 : speed/2;

	BTSerial->write(_rightMotor, PACKET_SIZE);
	BTSerial->write(_leftMotor, PACKET_SIZE);
	delay(_delayTime);
}

void NXTCommands::spin()
{
  
   move(_speed,true);
}

void NXTCommands::moveLeft()
{
   //implement later
}

void NXTCommands::moveRight()
{
  // Implement Later
}

void NXTCommands::moveForward()
{
  move(_speed);
}

void NXTCommands::moveBackward()
{
  move(-1*_speed);
}

void NXTCommands::stopMoving()
{
  move(0*_speed);
}

void NXTCommands::shoot()
{
        move(0);
        _shootMotor[5] = _speed;
        BTSerial->write(_shootMotor, PACKET_SIZE);
        delay(_delayTime*5);
        _shootMotor[5] = 0;
        BTSerial->write(_shootMotor, PACKET_SIZE);
        //move(_speed);
}

void NXTCommands::playTone(byte frequency, byte milliseconds)
{
	// flip the bytes for frequency and duration (LSB first is required)
	_frequencyLSB = (frequency & 0xFF);
	_frequencyMSB = ((frequency >> 8) & 0xFF);
	_durationLSB = (milliseconds & 0xFF);
	_durationMSB = ((milliseconds >> 8) & 0xFF);

	_tone[4] = _frequencyLSB;
	_tone[5] = _frequencyMSB;
	_tone[6] = _durationLSB;
	_tone[7] = _durationMSB;

	BTSerial->write(_tone, PACKET_SIZE);
	delay(_delayTime);
}

// Testing Routines
byte NXTCommands::getLeftMotorPacket(int byteIndex)
{
    return _leftMotor[byteIndex];
}

byte NXTCommands::getRightMotorPacket(int byteIndex)
{
    return _rightMotor[byteIndex];
}

byte NXTCommands::getShootMotorPacket(int byteIndex)
{
    return _shootMotor[byteIndex];
}

byte NXTCommands::getTonePacket(int byteIndex)
{
    return _tone[byteIndex];
}

byte NXTCommands::getSpeed()
{
    return _speed;
}

