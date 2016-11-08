/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "StaticElement.h"

namespace state {
    // Operations
    bool  StaticElement::isStatic() const{
        return 1;
    }
    bool StaticElement::isSpace () const{
        return 0; // à modifier plus tard
    }
    // erreurs de référence indéfinie lorsque l'on fait ca
    bool StaticElement::isFree () const{
        return 0; //modif plus tard
    }
    TypeID Element::getTypeID() const{
        return WALL; //test
    }


}