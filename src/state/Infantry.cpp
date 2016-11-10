#include "Infantry.h"
#include <typeinfo>
namespace state{
    Infantry::Infantry (){
    }
    TypeID Infantry::getTypeID(){
        return INFANTRY;
    }
    void Infantry::setTypeID(TypeID soldier){
        test=soldier;
    }

    bool  Infantry::equals(const Element& other) const{
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }
}
