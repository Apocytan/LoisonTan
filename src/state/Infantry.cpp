/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Infantry.h"

namespace state{
    Infantry::Infantry (){
    }
    TypeID const Infantry::getTypeID (){
        return INFANTRY;
    }

    bool const Infantry::equals (const Element& other){
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }
}
