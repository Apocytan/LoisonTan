#include "ProduceInfantryCommand.h"
#include <iostream>

namespace engine{

    ProduceInfantryCommand::ProduceInfantryCommand (int x, int y, state::ElementList* ListOfElements, state::ElementList* ListOfTurn, int playerColor){
        this->x=x;
        this->y=y;
        this->ListOfElements=ListOfElements;
        this->ListOfTurn=ListOfTurn;
        this->playerColor=playerColor;
    }
    ProduceInfantryCommand::~ProduceInfantryCommand (){
        
    }
    CommandTypeID ProduceInfantryCommand::getCommandTypeID () const{
        return PRODUCEINFANTRYCOMMAND;
    }
    int ProduceInfantryCommand::getX (){
        return x;
    }
    int ProduceInfantryCommand::getY (){
        return y;
    }
    state::ElementList* ProduceInfantryCommand::getListOfElements (){
        return ListOfElements;
    }
    state::ElementList* ProduceInfantryCommand::getListOfTurn (){
        return ListOfTurn;
    }
    int ProduceInfantryCommand::getPlayerColor (){
        return playerColor;
    }
    
}