#include "ProduceUnit.h"
#include <iostream>
namespace engine {
    ProduceUnit::ProduceUnit (int x, int y, state::MobileElement* unit)  {
        // mettre ses coordonnéees à la case voulue
        
        // définir l'unité créée, ruler s'occupera de définir la couleur de l'unité crée
        std::cout << "Unit Produced " << std::endl;
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
            std::cout << "Infantry" << std::endl;
            free (unit);
            delete unit;
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