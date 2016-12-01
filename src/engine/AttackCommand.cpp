#include "AttackCommand.h"
#include <iostream>

namespace engine{
    
    AttackCommand::AttackCommand (state::Element* attacker, state::Element* defender, state::ElementList* StaticMap, state::ElementList* MapUnits){
        this->attacker=attacker;
        this->defender=defender;
        this->StaticMap=StaticMap;
        this->MapUnits=MapUnits;
    }   
    AttackCommand::~AttackCommand (){
    
    }
    CommandTypeID AttackCommand::getCommandTypeID () const{
        return ATTACKCOMMAND;
    }
    
    state::Element* AttackCommand::getAttacker (){
        return attacker;
    }
    state::Element* AttackCommand::getDefender (){
        return defender;
    }
    state::ElementList* AttackCommand::getStaticMap (){
        return StaticMap;
    }
    state::ElementList* AttackCommand::getMapUnits (){
        return MapUnits;
    }
    
}