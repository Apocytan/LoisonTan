#include "Tank.h"
#include <typeinfo>
namespace state{
    
    Tank::Tank (){

    }
    TypeID Tank::getTypeID () const{
        return TANK;
    }
    bool Tank::equals (const Element& other) const{
                if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }


}
