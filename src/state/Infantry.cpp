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
     bool Infantry::isAir () const{
         return 0;
     }
}
