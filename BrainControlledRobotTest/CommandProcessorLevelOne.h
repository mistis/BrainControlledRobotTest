//
//  CommandProcessorLevelOne.h
//  
//
//  Created by misti stevens on 10/15/15.
//
//

#ifndef ____CommandProcessorLevelOne__
#define ____CommandProcessorLevelOne__

class CommandProcessorLevelOne {

    const int   mSamplesToProcess;
    int         mSumOfDifferences;
    int         mPreviousCommand;
    
public:
    
    CommandProcessorLevelOne();
    CommandProcessorLevelOne(const int samplingFrame);
    
    // Processing routines
    const int ProcessCommand(const int attentionVal, const int meditationVal, const int sample);
    
};

#endif
