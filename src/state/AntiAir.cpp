/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "AntiAir.h"
#include <typeinfo>
namespace state {
    
    AntiAir::AntiAir (){
    }
    
    TypeID const AntiAir::getTypeID (){
        return ANTIAIR;
    }
    bool const AntiAir::equals (const Element& other){
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }
}

