#include "Space.h"
#include <typeinfo>
namespace state{
    Space::Space (SpaceTypeID sid){
        this->x=x;
        this->y=y;
    
    } 
    bool const Space::isSpace (){
        return true;
    }
    TypeID const Space::getTypeID (){
        return SPACE;
    }
    SpaceTypeID const Space::getSpaceTypeID (){
        return spaceTypeID;
    }
    void Space::setSpaceTypeID (SpaceTypeID sid, bool free){
        this->spaceTypeID=sid;
        this->free=free;
    }
    bool const Space::equals (const Element& other){
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }
    bool isFree (){
        int free=1;
        if (free==1) return 1;
        else return 0;
    }
}