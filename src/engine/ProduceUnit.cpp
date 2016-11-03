/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state/MobileElement.h"
#include "ProduceUnit.h"

namespace engine {
    void ProduceUnit::ProduceUnit (int x, int y, state::MobileElement unit)  {
        // mettre ses coordonnéees à la case voulue
        
        // définir l'unité créée, ruler s'occupera de définir la couleur de l'unité crée
        
        if (unit.getTypeID() == "FIGHTER"){
            unit.setSpeed(5);
            unit.setPosition(x+y*33); 
            unit.setRank(0);
            unit.setHp(10);
            unit.setDamage(4);
        }
        if (unit.getTypeID() =="INFANTRY"){
            unit.setSpeed(3);
            unit.setPosition(x+y*33); 
            unit.setRank(0);
            unit.setHp(10);
            unit.setDamage(3);
        }
        if (unit.getTypeID() == "TANK"){
            unit.setSpeed(4);
            unit.setPosition(x+y*33); 
            unit.setRank(0);
            unit.setHp(10);
            unit.setDamage(5);
        }
        if (unit.getTypeID() == "ANTIAIR"){
            unit.setSpeed(4);
            unit.setPosition(x+y*33); 
            unit.setRank(0);
            unit.setHp(10);
            unit.setDamage(4);
        }
    }
    
    void apply (state::State& s, bool notify){
        if (notify==1){
            
        }
    }
    void undo (state::State& s, bool notify){
        if (notify==0){
            
        }
    }
    
}