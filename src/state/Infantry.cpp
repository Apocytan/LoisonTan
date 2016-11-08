/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Infantry.h"
#include <typeinfo>
namespace state{
    Infantry::Infantry (){
    }
    TypeID Infantry::getTypeID() const{
        return INFANTRY;
    }

    bool  Infantry::equals(const Element& other) const{
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }
}
