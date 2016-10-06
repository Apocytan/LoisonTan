/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Wall.h"

namespace state{
    Wall::Wall (WallTypeID wid){
        this->x=x;
        this->y=y;
    }
    bool const Wall::isSpace (){
        return 0;
    }
    TypeID const Wall::getTypeID (){
        return WALL;
    }
    WallTypeID const Wall::getWallTypeID ()
    {
        /*switch(this->WallTypeID){
            case SEA:{
                return SEA;
            }
            case WOODS:{
                return WOODS;
            }
        }*/
    }
    void Wall::setWallTypeID (WallTypeID wid){
        //this->WallTypeID=wid;
    }
    bool const Wall::equals (const Element& other){
         if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }

    }
    
}