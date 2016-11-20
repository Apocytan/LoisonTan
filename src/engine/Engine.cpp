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
    void  Engine::ProduceInfantry (int x, int y,state::Infantry *unit, state::ElementList *ListOfElements){

            unit->setSpeed(3);
            unit->setX(x);
            unit->setY(y);
            unit->setPosition(x+y*33); 
            unit->setRank(0);
            unit->setHp(10);
            unit->setDamage(3);
            std::cout<< "Infantry created" <<std::endl;
            state::Element* unite=static_cast<state::Element*>(unit);
            unite->setX(unit->getX());
            unite->setY(unit->getY());
            unite=ListOfElements->elements.at(x+y*33);
    }
    void Engine::ProduceFighter(int x, int y,state::Fighter *unit, state::ElementList *ListOfElements){
            unit->setSpeed(5);
            unit->setX(x);
            unit->setY(y);
            unit->setPosition(x+y*33); 
            unit->setRank(0);
            unit->setHp(10);
            unit->setDamage(3);
            std::cout<< "Fighter created" <<std::endl;
            state::Element* unite=static_cast<state::Element*>(unit);
            unite->setX(unit->getX());
            unite->setY(unit->getY());
            unite=ListOfElements->elements.at(x+y*33);
    }
    
void Engine::MoveUnit (state::Element* mover, state::Element* destination, state::ElementList StaticMapElements){
        if(destination->isStatic()!=1 || destination->getTypeID()!=1 || destination->getTypeID()!=6){
            if(destination->isStatic()!=1){
                std::cout<< "vous tentez de vous déplacer sur un élément mobile" <<std::endl;
            }else{
                if(mover->getTypeID()!=2){
                    std::cout<< "Votre unité ne peut se déplacer sur ce type d'élément" <<std::endl;
                }else{
                    destination=mover;
                    int x=mover->getX();
                    int y=mover->getY();
                    mover=StaticMapElements.elements.at(x+y*33);
                }
            }
            
        }else{
            destination=mover;
            int x=mover->getX();
            int y=mover->getY();
            mover=StaticMapElements.elements.at(x+y*33);
        }
        
    }
    
void  Engine::CaptureEnemy (state::Infantry *capturer, state::Structure *captured){
    
        if (capturer->getColor() != captured->getColor()){
            if(captured->isFree()==1){
                // si batiment non capturé
                if  (captured->getCapturepoints() !=0){
                        captured->setCapturepoints(captured->getCapturepoints()-capturer->getHp());
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
    
        void Engine::AttackEnemy(state::Element* attack, state::Element* defend ) {
            bool canAct =1;
            state::MobileElement* attacker=static_cast<state::MobileElement*>(attack);
            state::MobileElement* defender=static_cast<state::MobileElement*>(defend);
            int degat = attacker->getDamage()*attacker->getHp()*0.1;
            // [CONDITIONS D'ATTAQUE]
            // [Point d'action]
        if (canAct){
            // [Couleurs différentes]
            if (attacker->getColor() != defender->getColor()){
                defender->setHp(degat); // HP du défenseur = Dégat de l'attaquant * ses hp(max10) * 0.1
                std::cout << "Vous lui avez infligé " << degat << std::endl;
                canAct='0';
                // [Unité attaquée non vaincue => contre-attaque]
                if(defender->getHp()>0) attacker->setHp(defender->getDamage()*defender->getHp()*0.1);
                    // [Unité attaquée meurt => attaquant promu]
                else attacker->setRank(1);
            }
            else{}
        }
    
        }
}