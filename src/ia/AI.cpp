#include "AI.h"
#include <iostream>
#include <cmath>
#include <typeinfo>
namespace ia{
    AI::AI(){
        
    }
    AI::AI(state::State* mainState, engine::Engine* mainEngine){
        this->mainState=mainState;
        this->mainEngine=mainEngine;
    }
    AI::~AI(){
        
    }
    bool AI::nextLocation(int xdep,int ydep, int xarr, int yarr) const{
        int range= sqrt(abs(xdep-xarr)*abs(xdep-xarr)+abs(ydep-yarr)*abs(ydep-yarr));
        if(range<=1){
            if(xarr<33 && yarr<16){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    
};