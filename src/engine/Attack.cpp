#include "Attack.h"

namespace engine{

    Attack::Attack (state::Element* attacker, state::Element* defender, state::ElementList* StaticMap, state::ElementList* MapUnits){
        this->attacker=attacker;
        this->defender=defender;
        this->StaticMap=StaticMap;
        this->MapUnits=MapUnits;
    }
    
    Attack::~Attack (){  
    }
    
    void Attack::execute () const{
        state::MobileElement* attack=static_cast<state::MobileElement*>(attacker);
        state::MobileElement* defend=static_cast<state::MobileElement*>(defender);
        int damageatk = attack->getDamage()*attack->getHp()*0.1;
        //int damagedef = defender->getDamage()*defender->getHp()/10;
        int range = abs((defend->getY()-attack->getY())+(defend->getX()-attack->getX()));
            // [CONDITIONS D'ATTAQUE]
            // [Point d'action]
        if (range==1){
                // [Test couleurs différentes]
            if (attack->getColor() != defend->getColor()){
                defend->setHp(defend->getHp()-damageatk); // HP du défenseur = Dégat de l'attaquant * ses hp(max10) * 0.1
                std::cout << "Vous lui avez infligé " << damageatk << std::endl;
                        // [Unité attaquée non vaincue => contre-attaque]
            if(defend->getHp()>0){
                if(defend->getDamage()*defend->getHp()/10<1){
                    attack->setHp(attack->getHp()-1);
                }else{
                    attack->setHp(attack->getHp()-defend->getDamage()*defend->getHp()/10);
                }
                       // [Unité attaquante détruite lors de la contre-attaque]
                if(attack->getHp()==0){
                    int x=attacker->getX();
                    int y=attacker->getY();
                    MapUnits->elements.erase(MapUnits->elements.begin()+x+y*33);
                    MapUnits->elements.insert(MapUnits->elements.begin()+x+y*33,StaticMap->elements.at(x+y*33));
                }
            }else {
                      // [Unité attaquée meurt => attaquant promu]
                attack->setRank(1);
                      // [Tuile décor changé car unité attaquée détruite]
                int x=defender->getX();
                int y=defender->getY();
                MapUnits->elements.erase(MapUnits->elements.begin()+x+y*33);
                MapUnits->elements.insert(MapUnits->elements.begin()+x+y*33,StaticMap->elements.at(x+y*33));
            }
                    
        }
        
    }
    std::cout<< "Vie restant de l'attaquant : " << attack->getHp() <<std::endl;
    std::cout<<"Vie restant du défenseur : " <<defend->getHp()<<std::endl;
    }
    
}


