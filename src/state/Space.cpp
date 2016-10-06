/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Space.h"

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
        /*enum SpaceTypeID {ROAD,GRASS,MINE,BUILDING,HEADQUARTER,FACTORY,AIRPORT}
        switch(SpaceTypeID){
            case 1:{
                return ROAD;
            }
            case 2:{
                return GRASS;
            }
            case 3:{
                return MINE;
            }
            case 4:{
                return BUILDING;
            }
            case 5:{
                return HEADQUARTER;
            }
            case 6:{
                return FACTORY;
            }
            case 7:{
                return AIRPORT;
            }
        }*/
    }
    void Space::setSpaceTypeID (SpaceTypeID sid){
        //this->SpaceTypeID=sid;
    }
    bool const Space::equals (const Element& other){
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
    }
    
}