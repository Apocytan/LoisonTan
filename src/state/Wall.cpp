#include "Wall.h"
#include <typeinfo>
namespace state{
    /*Wall::Wall (WallTypeID wid){
        this->x=x;
        this->y=y;
    }*/
    /*bool  Wall::isSpace() const{
        //return 0;
    }*/
    /*TypeID  Element::getTypeID ()const{
        return WALL;
    }*/
    WallTypeID  Wall::getWallTypeID () const
    {
        return  wallTypeID ;
    }
    void Wall::setWallTypeID (WallTypeID wid){
        this->wallTypeID=wid;
    }
    bool Wall::equals (const Element& other) const{
         if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }

    }
    
}