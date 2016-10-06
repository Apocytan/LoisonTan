/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Tank.h"

namespace state{
    
    Tank::Tank (){

    }
    TypeID const Tank::getTypeID (){
        return TANK;
    }
    bool const Tank::equals (const Element& other){
                if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }


}
