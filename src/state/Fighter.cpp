/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Fighter.h"

namespace state {

  /// class Fighter - 
    Fighter::Fighter (){
    }
    TypeID const Fighter::getTypeID (){
        return FIGHTER;
    }

    bool const Fighter::equals (const Element& other){
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }

}