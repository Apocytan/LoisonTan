#include "Ruler.h"
#include "MoveUnit.h"
#include <iostream>
#include <stack>
#include "../state.h"
//CONSIDERONS QUE canAct passe à 0 après toutes les actions effectuées
namespace engine{
 
    Ruler::Ruler (ActionList& actions, const state::State& cstate , const CommandSet& command ): currentState(cstate), commands(command),actions(actions) { 
        /*this->actions = actions;
        this->currentState=cstate;
        this->commands=command;*/
    }
    
    Ruler::~Ruler() {   
    }
    void Ruler::apply() {
        
    }
    void Ruler::moveChar(state::MobileElement* mover, state::StaticElement* destination) { 
        // la case est-elle franchissable
        // quel est le type d'unité qui souhaite se déplacer?
        int distance = (destination->getY()-mover->getY())+(destination->getX()-mover->getX());
        
        // la case est-elle à portée?
        if (canAct){
            if (mover->getSpeed()>= distance){ 
            // la case est-elle libérée ?
                if (destination->isFree() == 1){
                    if (mover->getTypeID() == 2){ // FIGHTER
                    std::cout << "Unit moved" << std::endl;

                    }
                
                /*if (mover->getTypeID() == 3){ // INFANTRY
                    if (destination->getTypeID() == 0) std::cout << "Unreachable destination" << std::endl;
                    std::cout << "Unit moved" << std::endl;
                }*/
                
                    if (mover->getTypeID() == 3 || 4 || 5 ){ // 
                        if (destination->getTypeID() == 0) std::cout << "Unreachable destination" << std::endl;
                    std::cout << "Unit moved" << std::endl;
                    } 
                }else std::cout << "The designated target is already occupied by an unit" << std::endl;
            }else std::cout << "The designated target is out of range" << std::endl;
        }
    }
    
    void Ruler::attack(state::MobileElement* attacker, state::MobileElement* defender ) {
        // on teste les conditions d'attaques
        // les alliés ne peuvent pas s'entre attaquer
        if (canAct){
        if (attacker->getColor() != defender->getColor()){
            if (attacker->getTypeID()!=4 && defender->getTypeID()!=2){
            defender->setHp(attacker->getDamage()*attacker->getHp()*0.1); // HP du défenseur = Dégat de l'attaquant * ses hp(max10) * 0.1
            // si l'unité défendu n'est pas morte, elle contre attaque
                if(defender->getHp()>0) attacker->setHp(defender->getDamage()*defender->getHp()*0.1);
                // si elle meurt, l'attaquant est promu
                else attacker->setRank(1);
            }else std::cout << "This is not possible" << std::endl;
        }
        else{}
    }
    }
    
    void Ruler::produce (state::State current ,state::Structure building , state::MobileElement* unitproduce){
        // test du batiment concerné
        if (building.getStructureTypeID()==state::StructureTypeID::AIRPORT && building.isSpace()== 1){
            if (unitproduce->getTypeID() ==state::TypeID::FIGHTER){
                if(current.getIron()>=unitproduce->getCost()){
                    // création d'une unité
                    //state::ElementList::elements.push(unitproduce);
                    // mise à jour des ressources
                    current.setIron(current.getIron()-unitproduce->getCost());
                    // unité produite dont la couleur est la même que le batiment
                    unitproduce->setColor(building.getColor());
                }
            }
            
        }
        if (building.getStructureTypeID()==state::StructureTypeID::FACTORY && building.isSpace()== 1){
            if (unitproduce->getTypeID() ==state::TypeID::INFANTRY || unitproduce->getTypeID()==state::TypeID::TANK||unitproduce->getTypeID() ==state::TypeID::ANTIAIR ){
                if(current.getIron()>=unitproduce->getCost()){
                    //state::ElementList::elements.push(unitproduce); //ajout de l'unité
                    unitproduce->setColor(building.getColor());
                    current.setIron(current.getIron()-unitproduce->getCost());
                }
            }
        }

    }
    
    void Ruler::capture(state::MobileElement* capturer, state::Structure captured) {
        // lorsque couleur différente
        if(canAct){
            if (capturer->getColor() != captured.getColor()){
                // si batiment non capturé
                if(captured.getCapturepoints() !=0){
                    captured.setCapturepoints(captured.getCapturepoints()-capturer->getHp()); 
                }
            //si batiment capturé
                else{
                    captured.setColor(capturer->getColor()); // on change sa couleur
                    captured.setCapturepoints(20); // on remet ses points à 20
                }
            
            }
        }
    }
    
    void Ruler::setcanAct (bool can){
        canAct = can;
    }
    
    bool Ruler::getcanAct (){
        return canAct; 
    }
    /*state::Structure Ruler::tileIsBuilding(<std::string> tileLetter){
        state::Structure redfactory;
        if (tileLetter == "rA"){
            return redfactory;
        }
    }
    state::MobileElement* Ruler::tileIsMobileElement(<std::string> tileLetter){
        
    }*/
}



    
