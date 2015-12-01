//
//  CommandProcessorLevelOne.cpp
//  
//
//  Created by misti stevens on 10/15/15.
//
//

#include "CommandProcessorLevelOne.h"
#include "CommandDefinitions.h"

CommandProcessorLevelOne::CommandProcessorLevelOne() :
        mSamplesToProcess(1)
    ,   mSumOfDifferences(0)
    ,   mPreviousCommand(mHold)
{
    
}


CommandProcessorLevelOne::CommandProcessorLevelOne(const int samplingFrame) :
        mSamplesToProcess(samplingFrame)
    ,   mSumOfDifferences(0)
    ,   mPreviousCommand(mHold)
{
  
}

const int CommandProcessorLevelOne::ProcessCommand(const int attentionVal, const int meditationVal, const int sample)
{
    const int difference = attentionVal - meditationVal;
    
    bool sendCommand = sample == (mSamplesToProcess - 1);
    
    if (sendCommand) {
        if (difference >= 0 && attentionVal > 50) {
            if(difference > shootThreshold){
                return mShoot;
            }
            mPreviousCommand = mForward;
            return mForward;
        } else if (difference < 0 && meditationVal > 50){
            mPreviousCommand = mSpin;
            return mSpin;
        } else {
            mPreviousCommand = mHold;
            return mHold;
        }
    } else {
            return mPreviousCommand;
    }
}
