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
        }
        
        Element::~Element (){
 
        }
        
        int Element::getX () const{
            return x;
        }
        int Element::getY() const{
            return y;
        }

        void Element::setX(int x){
             this->x = x ;
        }
        void Element::setY(int y){
            this->y=y;
        }

        bool Element::isStatic () const{
            // if ...
            return 0;
            //if return 1
        }
        TypeID Element::getTypeID () const{
            return WALL;
        }   
}