#include "Structure.h"
#include <typeinfo>

namespace state{
    Structure::Structure (){
        
    }
    Structure::Structure (StructureTypeID sid,bool free, int color){
        this->structureTypeID=sid;
        this->free=free;
        this->color=color;
    }
    
    bool Structure::isFree () const{
        return free;
        
    }
    
    TypeID Structure::getTypeID () const{
        return STRUCTURE; //test
    }
    StructureTypeID Structure::getStructureTypeID () const{
        return structureTypeID;
    }
    void Structure::setStructureTypeID (StructureTypeID sid, bool free){
        this->structureTypeID=sid;
        this->free=free;
    }
    
    bool Structure::equals (const Element& other) const{
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }

    }
    

    int Structure::getColor () const{
        return color;
    }
    void Structure::setColor (int c){
        color = c;
    }
    int Structure::getCapturepoints () const{
        return capturepoints;
    }
    void Structure::setCapturepoints (int cp){
        capturepoints=cp;
    }

}
