/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "TypeID.h" //interface
#include "Element.h"
#include <typeinfo>

    /*protected :
        int x=0;
        int y=0;
        Direction orientation=0;
    */
namespace state{
        Element::Element(){
            x=0;
            y=0;
            orientation=NONE;
        }
        
        Element::~Element (){
            if(x && y &&orientation)
                delete &x;
                delete &y;
                delete &orientation;
            
        }
        
        int Element::getX () const{
            return x;
        }
        int Element::getY() const{
            return y;
        }
        Direction  Element::getOrientation() const{
            return orientation;
        }
        void Element::setX(int x){
             this->x = x ;
        }
        void Element::setY(int y){
            this->y=y;
        }
        void Element::setOrientation(Direction o){
            orientation=o;
        }
        bool Element::isStatic () const{
            // if ...
            return 0;
            //if return 1
        }

}