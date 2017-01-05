#include "ProduceFighterCommand.h"
#include <iostream>

namespace engine{
    
    ProduceFighterCommand::ProduceFighterCommand (int x, int y, state::ElementList* ListOfElements, state::ElementList* ListOfTurn, int playerColor){
        this->x=x;
        this->y=y;
        this->ListOfElements=ListOfElements;
        this->ListOfTurn=ListOfTurn;
        this->playerColor=playerColor;
    }
    ProduceFighterCommand::~ProduceFighterCommand (){
    
    }
    CommandTypeID ProduceFighterCommand::getCommandTypeID () const{
        return engine::PRODUCEFIGHTERCOMMAND;
    }
    
    int ProduceFighterCommand::getX (){
        return x;
    }
    int ProduceFighterCommand::getY (){
        return y;
    }
    state::ElementList* ProduceFighterCommand::getListOfElements (){
        return ListOfElements;
    }
    state::ElementList* ProduceFighterCommand::getListOfTurn (){
        return ListOfTurn;
    }
    int ProduceFighterCommand::getPlayerColor (){
        return playerColor;
    }
}