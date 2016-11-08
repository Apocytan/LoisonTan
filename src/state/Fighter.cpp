/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Fighter.h"
#include <typeinfo>
namespace state {

  /// class Fighter - 
    Fighter::Fighter (){

    }
    TypeID  Fighter::getTypeID () const{
        return FIGHTER;
    }

    bool  Fighter::equals (const Element& other) const{
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }

}