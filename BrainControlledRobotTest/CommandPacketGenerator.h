//
//  CommandPacketGenerator.h
//
//
//  Created by misti stevens on 10/16/15.
//
//


#ifndef ____CommandPacketGenerator__
#define ____CommandPacketGenerator__

#include "NXTCommands.h"

class CommandPacketGenerator {
    
    // This type can be changed later if needed
    Commands*  mCommandHandler;
    
public:
    
    CommandPacketGenerator(Commands* cmdGen);
    virtual ~CommandPacketGenerator();
    virtual void SendCommandPacket(const int commandNum);
};

#endif
