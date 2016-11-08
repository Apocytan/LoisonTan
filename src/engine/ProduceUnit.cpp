/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ProduceUnit.h"

namespace engine {
    ProduceUnit::ProduceUnit (int x, int y, state::MobileElement* unit)  {
        // mettre ses coordonnéees à la case voulue
        
        // définir l'unité créée, ruler s'occupera de définir la couleur de l'unité crée
        
        if (unit->getTypeID()==2){// FIGHTER
            unit->setSpeed(5);
            unit->setPosition(x+y*33); 
            unit->setRank(0);
            unit->setHp(10);
            unit->setDamage(4);
        }
        if (unit->getTypeID() ==3){ //INFANTRY
            unit->setSpeed(3);
            unit->setPosition(x+y*33); 
            unit->setRank(0);
            unit->setHp(10);
            unit->setDamage(3);
        }
        if (unit->getTypeID() == 4){ //TANK
            unit->setSpeed(4);
            unit->setPosition(x+y*33); 
            unit->setRank(0);
            unit->setHp(10);
            unit->setDamage(5);
        }
        if (unit->getTypeID() == 5){ //ANTIAIR
            unit->setSpeed(4);
            unit->setPosition(x+y*33); 
            unit->setRank(0);
            unit->setHp(10);
            unit->setDamage(4);
        }
    }
    
}