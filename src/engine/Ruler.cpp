/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ruler.h"
#include "state/MobileElement.h"
#include "state/StaticElement.h"
#include "state/State.h"
#include "state/Structure.h"
#include <stack>

namespace engine{

    Ruler::Ruler (ActionList& , const state::State& , const CommandSet& ) const{   
    }
    void Ruler::~Ruler() {   
    }
    void Ruler::apply() {
        
    }
    void Ruler::moveChar(state::MobileElement mover, state::StaticElement destination) { 
        // la case est-elle franchissable
        // quel est le type d'unité qui souhaite se déplacer?
        int distance = (destination.getY()-mover.getY())+(destination.getX()-mover.getX());
        
        // la case est-elle à portée?
        if (mover.getSpeed()>= distance){ 
            // la case est-elle libérée ?
            if (destination.isFree() == 1){
                if (mover.getTypeID == "FIGHTER"){
                    std::cout << "Unit moved" << std::endl;
                }
                
                if (mover.getTypeID == "INFANTRY"){
                    if (destination.getTypeID == "SEA") std::cout << "Unreachable destination" << std::endl;
                    std::cout << "Unit moved" << std::endl;
                }
                
                if (mover.getTypeID == "TANK"||"ANTIAIR"){
                    if (destination.getTypeID == "SEA" || destination.getTypeID == "WOODS") std::cout << "Unreachable destination" << std::endl;
                    std::cout << "Unit moved" << std::endl;
                } 
            }else std::cout << "The designated target is already occupied by an unit" << std::endl;
        }else std::cout << "The designated target is out of range" << std::endl;
    }
    
    void Ruler::attack(state::MobileElement attacker, state::MobileElement defender ) {
        // on teste les conditions d'attaques
        // les alliés ne peuvent pas s'entre attaquer
        if (attacker.getColor() != defender.getColor()){
            if (attacker.getTypeID()!="TANK" && defender.getTypeID()!="FIGHTER"){
            defender.setHp(attacker.getDamage()*attacker.getHp()*0.1); // HP du défenseur = Dégat de l'attaquant * ses hp(max10) * 0.1
            // si l'unité défendu n'est pas morte, elle contre attaque
                if(defender.getHp()>0) attacker.setHp(defender.getDamage()*defender.getHp()*0.1);
                // si elle meurt, l'attaquant est promu
                else attacker.setRank(1);
            }else std::cout << "Ceci n'est pas une cible appropriée" << std::endl;
        }
        else{}
    }
    
    void Ruler::produce (state::State current ,state::Structure building , state::MobileElement unitproduce){
        // test du batiment concerné
        if (building.getTypeID()==state::Structure::StructureTypeID::AIRPORT && building.isSpace()== 1){
            if (unitproduce.getTypeID() ==state::Element::TypeID::FIGHTER){
                if(current.getIron()>=unitproduce.getCost()){
                    // création d'une unité
                    state::ElementList::elements.push(unitproduce);
                    // mise à jour des ressources
                    current.setIron(current.getIron()-unitproduce.getCost());
                    // unité produite dont la couleur est la même que le batiment
                    unitproduce.setColor(building.getColor());
                }
            }
            
        }
        if (building.getTypeID()==state::Structure::StructureTypeID::FACTORY && building.isSpace()== 1){
            if (unitproduce.getTypeID() ==state::Element::TypeID::INFANTRY || unitproduce.getTypeID()==state::Element::TypeID::TANK||unitproduce.getTypeID() ==state::Element::TypeID::ANTIAIR ){
                if(current.getIron()>=unitproduce.getCost()){
                    state::ElementList::elements.push(unitproduce);
                    unitproduce.setColor(building.getColor());
                    current.setIron(current.getIron()-unitproduce.getCost());
                }
            }

    }
    
    void Ruler::capture(state::MobileElement capturer, state::Structure captured) {
        // lorsque couleur différente
        if (capturer.getColor() != captured.getColor()){
            // si batiment non capturé
            if(captured.getCapturepoints() !=0){
                captured.setCapturepoints(captured.getCapturepoints()-capturer.getHp()); 
               
            }
            //si batiment capturé
            else{
                captured.setColor(capturer.getColor()); // on change sa couleur
                captured.setCapturepoints(20); // on remet ses points à 20
            }
            
        }
    }
    void Ruler::setcanAct (bool can){
        canAct = can;
    }
    bool Ruler::getcanAct (){
        return canAct; 
    }
}
  

    
