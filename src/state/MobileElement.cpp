/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "MobileElement.h" 
#include "Element.h"
namespace state{
        MobileElement::MobileElement(){
            this->speed=speed;
            this->position=position;
            this->color=color;
            this->rank=rank;
            this->hitpoints=hitpoints;
            this->damage=damage;
        }
        
        bool const isStatic() {
            return false;
            }
            
        
        bool const MobileElement::equals(const Element& other){
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
        }
        
        // Getters
        Direction MobileElement::getDirection() const{
            return orientation;
        }
        int MobileElement::getSpeed() const{
            return speed;
        }
        int MobileElement::getPosition() const{
            return position;
        }
        int MobileElement::getColor() const{
            return color;
        }
        bool MobileElement::getRank() const {
            return rank;
        }
        int MobileElement::getHp() const{
            return hitpoints;
        }
        int MobileElement::getDamage() const{
            return damage;
        }
        
        // définition des setters
        void MobileElement::setDirection(Direction d){
            orientation=d;
        }
        void MobileElement::setSpeed(int sp){
            speed = sp;
        }
        void MobileElement::setPosition(int pos){
            position = pos;
        }
        
        void MobileElement::setColor(int c){
            color=c;
        }
        void MobileElement::setRank(bool rank){
            this->rank=rank;
        }
        void MobileElement::setHp(int hp){
            hitpoints=hp;
        }
        void MobileElement::setDamage(int dam){
            damage=dam;
        }
        
};
