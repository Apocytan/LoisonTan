#include "Engine.h"
#include <SFML/Window/Mouse.hpp>
#include <iostream>
namespace engine{
    
    Engine::~Engine (){
        
    }
 
    Engine::Engine (){
        
    }
    EngineMode  Engine::getMode () const{
        return PLAY; 
    }

    void  Engine::addCommand (Command* cmd){
        commands.push_back(cmd);
        std::cout<<"COMMAND ADDED" << std::endl;
    }
    /*void  Engine::takeCommands (CommandSet& commands){
        // prend les commandes du clavier
        
        
    }*/

    void  Engine::loadLevel (const char* file_name) const{
        
    }
    void  Engine::setMode (EngineMode mode){
        
    }

    



    
    // renvoi le type pour ruler
    void  Engine::ProduceInfantry (int x, int y, state::ElementList *ListOfUnits, state::ElementList* ListOfTurn,int playercolor){
            // [ On créé son instance]
            state::MobileElement* unit ;
            state::Infantry* soldat = static_cast<state::Infantry*>(unit);
            soldat = new state::Infantry();
            // [ On définit ses statistiques]
            soldat->setSpeed(3);
            soldat->setX(x);
            soldat->setY(y);
            soldat->setPosition(x+y*33); 
            soldat->setRank(0);
            soldat->setHp(10);
            soldat->setDamage(3);
            soldat->setColor(playercolor);
            // [ On ajoute sa tuile ]
            ListOfUnits->elements.erase(ListOfUnits->elements.begin()+x+y*33);
            ListOfUnits->elements.insert(ListOfUnits->elements.begin()+x+y*33,soldat);
            ListOfTurn->elements.push_back(soldat);
            std::cout<< "Fighter created" <<std::endl;
    }
    void Engine::ProduceFighter(int x, int y, state::ElementList *ListOfUnits, state::ElementList* ListOfTurn,int playercolor){
            // [ On créé son instance]
            state::MobileElement* unit ;
            state::Fighter* avion = static_cast<state::Fighter*>(unit);
            avion = new state::Fighter();
            // [ On définit ses statistiques]
            avion->setSpeed(5);
            avion->setX(x);
            avion->setY(y);
            avion->setPosition(x+y*33); 
            avion->setRank(0);
            avion->setHp(10);
            avion->setDamage(3);
            avion->setColor(playercolor);
            // [ On ajoute sa tuile ]
            ListOfUnits->elements.erase(ListOfUnits->elements.begin()+x+y*33);
            ListOfUnits->elements.insert(ListOfUnits->elements.begin()+x+y*33,avion);
            ListOfTurn->elements.push_back(avion);
            std::cout<< "Fighter created" <<std::endl;
    }
    
void Engine::MoveUnit (state::Element* mover, state::Element* destination, state::ElementList* StaticMapElements, state::ElementList* MapUnits){
    if(mover->isStatic()!=1 && destination->isStatic()==1){
            int i=mover->getX();
            int j=mover->getY();
            std::cout<<mover->getX()<< i<<std::endl;
            std::cout<<mover->getY()<< j<< std::endl;
            
            mover->setX(destination->getX());
            mover->setY(destination->getY());
            std::cout<<mover->getX()<< i<<std::endl;
            std::cout<<mover->getY()<< j<< std::endl;
            int x=destination->getX();
            int y=destination->getY();
            mover->setX(x);
            mover->setY(y);
            MapUnits->elements.erase(MapUnits->elements.begin()+x+y*33);//on efface l'élément de destination
            MapUnits->elements.insert(MapUnits->elements.begin()+x+y*33,mover);//on le remplace par l'élément que l'on bouge
            
            MapUnits->elements.erase(MapUnits->elements.begin()+i+j*33);//on efface l'élément de départ
            MapUnits->elements.insert(MapUnits->elements.begin()+i+j*33,StaticMapElements->elements.at(i+j*33));//on insert l'élément issus de la map où se trouvait notre unité
            
            
            
    }else{
        std::cout<<"votre unité n'est pas déplaçable"<<std::endl;
    }
        //}
        
}
    
void  Engine::CaptureEnemy (state::Infantry *capturer, state::Structure *captured){
    
        if (capturer->getColor() != captured->getColor()){
            if(captured->isFree()==1){
                captured->setCapturepoints(captured->getCapturepoints()-capturer->getHp());
                // si batiment non capturé
                if  (captured->getCapturepoints() >0){
                      std::cout<<"Il reste " << captured->getCapturepoints()<< "points de capture"<< std::endl;  
                }
            //si batiment capturé
                else{
                    captured->setColor(capturer->getColor()); // on change sa couleur
                    captured->setCapturepoints(20); // on remet ses points à 20
                }
                /*capturer->setX(x);
                capturer->setY(y);*/
            }
        }
}
    
void Engine::AttackEnemy(state::Element* attack, state::Element* defend, state::ElementList* StaticMapElements, state::ElementList* MapUnits ) {
   
    state::MobileElement* attacker=static_cast<state::MobileElement*>(attack);
    state::MobileElement* defender=static_cast<state::MobileElement*>(defend);
    int damageatk = attacker->getDamage()*attacker->getHp()*0.1;
    //int damagedef = defender->getDamage()*defender->getHp()/10;
    int range = abs((defend->getY()-attack->getY())+(defend->getX()-attack->getX()));
           // [CONDITIONS D'ATTAQUE]
            // [Point d'action]
    if (range==1){
           // [Couleurs différentes]
        if (attacker->getColor() != defender->getColor()){
            defender->setHp(defender->getHp()-damageatk); // HP du défenseur = Dégat de l'attaquant * ses hp(max10) * 0.1
            std::cout << "Vous lui avez infligé " << damageatk << std::endl;
                        // [Unité attaquée non vaincue => contre-attaque]
            if(defender->getHp()>0){
                if(defender->getDamage()*defender->getHp()/10<1){
                    attacker->setHp(attacker->getHp()-1);
                }else{
                    attacker->setHp(attacker->getHp()-defender->getDamage()*defender->getHp()/10);
                }
                       // [Unité attaquante détruite lors de la contre-attaque]
                if(attacker->getHp()==0){
                    int x=attacker->getX();
                    int y=attacker->getY();
                    MapUnits->elements.erase(MapUnits->elements.begin()+x+y*33);
                    MapUnits->elements.insert(MapUnits->elements.begin()+x+y*33,StaticMapElements->elements.at(x+y*33));
                }
            }else {
                      // [Unité attaquée meurt => attaquant promu]
                attacker->setRank(1);
                        // [Tuile décor changé car unité attaquée détruite]
                int x=defender->getX();
                int y=defender->getY();
                MapUnits->elements.erase(MapUnits->elements.begin()+x+y*33);
                MapUnits->elements.insert(MapUnits->elements.begin()+x+y*33,StaticMapElements->elements.at(x+y*33));
            }
                    
        }
        
    }
    std::cout<< "vie de l'attaquant : " << attacker->getHp() <<std::endl;
    std::cout<<"vie du défenseur: "<<defender->getHp()<<std::endl;
}
}