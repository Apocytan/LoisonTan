#include "Space.h"
#include <typeinfo>
namespace state{
    Space::Space (SpaceTypeID sid){
        this->spaceTypeID=sid;
        this->free=1;
    
    } 
    bool  Space::isSpace() const{
        return true;
    }
    TypeID Space::getTypeID() const{
        return SPACE;
    }
    SpaceTypeID Space::getSpaceTypeID () const{
        return spaceTypeID;
    }
    void Space::setSpaceTypeID (SpaceTypeID sid, bool free){
        this->spaceTypeID=sid;
        this->free=free;
    }
    bool Space::equals (const Element& other) const{
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }
    bool Space::isFree (){
        return free;
    }
}
