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
    TypeID StaticElement::getTypeID() const{
        return WALL; //test
    }


}