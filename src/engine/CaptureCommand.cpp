#include "CaptureCommand.h"
#include <iostream>

namespace engine{
    
    CaptureCommand::CaptureCommand (state::Infantry* capturer, state::Structure* captured){
        this->capturer=capturer;
        this->captured=captured;
    }
    
    CaptureCommand::~CaptureCommand (){
        
    }
    
    CommandTypeID CaptureCommand::getCommandTypeID () const{
        return engine::CAPTURECOMMAND;
    }
            
    state::Infantry* CaptureCommand::getCapturer (){
        return capturer;
    }
    
    state::Structure* CaptureCommand::getCaptured (){
        return captured;
    }
    
}