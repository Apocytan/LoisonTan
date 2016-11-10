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