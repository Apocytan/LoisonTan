/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Structure.h"
#include <typeinfo>

namespace state{
    Structure (StructureTypeID sid){  
    }
    bool isFree () const{
        if (free==){
        return 1;
        }
        else{
            return 0;
        }
        
    }
    TypeID getTypeID () const{
        
    }
    StructureTypeID Structure::getStructureTypeID () const{
        return structureTypeID;
    }
    void Structure::setStructureTypeID (StructureTypeID sid, bool free){
        this->structureTypeID=sid;
        this->free=free;
    }
    
    bool equals (const Element& other) const{
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
