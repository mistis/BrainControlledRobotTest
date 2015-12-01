

// Brain Controlled Robot
// This file is a modification of the following:

// Arduino Brain Library - Brain Serial Test
// Description: Grabs brain data from the serial RX pin and sends CSV out over the TX pin (Half duplex.)
// More info: https://github.com/kitschpatrol/Arduino-Brain-Library
// Author: Eric Mika, 2010 revised in 2014

#include <Brain.h>
#include <SoftwareSerial.h>
#include "CommandProcessorLevelOne.h"
#include "CommandDefinitions.h" 
#include "CommandPacketGenerator.h"

//
// State variables
//

int mSampleNumber = 0;

//
// Set up objects
//

// Set up the Command Processor
const int mNumberOfSamples = 1;
CommandProcessorLevelOne mCommmandProcessor(mNumberOfSamples);

// Set up the Command Packet Generator
CommandPacketGenerator mCommandPacketHandler();

// Set up the brain parser, pass it the hardware serial object you want to listen on.
Brain brain(Serial);

void setup() {
    // Start the hardware serial.
    Serial.begin(9600);
}

//
// Main loop
//

void loop() {
    // Expect packets about once per second.
    // The .readCSV() function returns a string (well, char*) listing the most recent brain data, in the following format:
    // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"    
    if (brain.update()) {
        // Read the data from the headset
        Serial.println(brain.readErrors());
        Serial.println(brain.readCSV());

        // Process command state
        const int command = mCommmandProcessor.ProcessCommand(brain.readAttention(), brain.readMeditation(), mSampleNumber);
        //Serial.print("Command: ");
        //Serial.println(command);

        // Send appropriate command, or maintain current state
        mCommandPacketHandler.SendCommandPacket(command);
        //Serial.println("Command Packet Sent");

        // Update the sample number --> wrap the sample number if needed 
        mSampleNumber = mSampleNumber < mNumberOfSamples ? mSampleNumber + 1 : 0;
    }
}
