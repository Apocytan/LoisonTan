#include "MoveCommand.h"
#include <iostream>

namespace engine{
    
    MoveCommand::MoveCommand (state::Element* mover, state::Element* destination, state::ElementList* StaticMapElements, state::ElementList* MapUnits){
        this->mover=mover;
        this->destination=destination;
        this->StaticMapElements=StaticMapElements;
        this->MapUnits=MapUnits;
    }
    MoveCommand::~MoveCommand (){
    }
    CommandTypeID MoveCommand::getCommandTypeID () const{
        return MOVECOMMAND;
    }
    
    state::Element* MoveCommand::getMover (){
        return mover;
    }
    state::Element* MoveCommand::getDestination (){
        return destination;
    }
    state::ElementList* MoveCommand::getStaticMapElements (){
        return StaticMapElements;
    }
    state::ElementList* MoveCommand::getMapUnits (){
        return MapUnits;
    }
    
}