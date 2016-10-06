/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "State.h"
#include "ElementList.h"
#include "ElementGrid.h"

namespace state{
    State::State() : chars(*this),grid(*this) {
        this->iron=iron;
        this->units=units;
    }
    State::~State (){
        if (&iron){
            delete &iron;
        }
        if (&units){
            delete &units;
        }
    }
    int State::getIron() const{
        return iron;
    }
    int State::getUnit() const{
        return units;
    }

    ElementGrid& State::getGrid (){
        return grid;
    }

    ElementList& State::getChars (){
        return chars;
    }
    MobileElement* State::getChar (int idx){
        
    }
    void State::setIron (int res){
        this->iron=res;
    }
    void State::setUnits (int count){
        this->units=count;
    }
    void State::setGrid (const ElementGrid& grid){
        //this->grid=grid;
    }
    void State::setChars (const ElementList& list){
        //this->chars=list;
    }
}