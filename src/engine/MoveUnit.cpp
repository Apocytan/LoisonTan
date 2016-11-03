/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <src/state/State.h>
#include "MoveUnit.h"

namespace engine{
    
    void MoveUnit (int index){
        
    }
    void MoveUnit::setCoords (int destinationx, int destinationy) const{
        this-> destination_x = destinationx;
        this->destination_y = destinationy;
        
    }
    void MoveUnit::setDirection (state::Direction prev, state::Direction next) const{
        this->prevDirection=prev;
        this->newDirection=next;
    }
    void MoveUnit::apply (state::State& s, bool notify){
        
        notify = 1;
    }
    void MoveUnit::undo (state::State& s, bool notify){
        
        notify =0;
    }
}