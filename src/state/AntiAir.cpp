#include "AntiAir.h"
#include <typeinfo>
namespace state {
    
    AntiAir::AntiAir (){
    }
    
    TypeID AntiAir::getTypeID() const{
        return ANTIAIR;
    }
    bool AntiAir::equals (const Element& other) const{
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }
}

