#include <iostream>
#include "State.h"
#include "ElementList.h"
#include "ElementGrid.h"

using namespace state;
    State::State(): chars(*this),grid(*this){
    }
    State::~State (){
    }


    ElementGrid& State::getGrid (){
        return grid;
    }

    ElementList& State::getChars (){
        return chars;
    }

    void State::setGrid (const ElementGrid& grid){
        //this->grid&=grid;
    }
    void State::setChars (const ElementList& list){
       // this->chars&=list;
    }
