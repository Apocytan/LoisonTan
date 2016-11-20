#include "Wall.h"
#include <typeinfo>
namespace state{
    Wall::Wall (WallTypeID wid){
        this->wallTypeID=wid;
        this->free=1;
    }
    bool  Wall::isSpace() const{
        return false;
    }

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
    TypeID Wall::getTypeID () const{
        return state::TypeID::WALL;
    }
    
    bool Wall::isFree () const{
        return free;
    }
    
}