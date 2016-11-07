/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CaptureBuilding.h"

namespace engine {
    CaptureBuilding::CaptureBuilding (int x, int y, state::StructureTypeID BuildingType){
        this-> x = x;
        this->y = y;
        this->BuildingType = BuildingType;
     }
    /*void CaptureBuilding::apply (state::State& s, bool notify){
        
    }
    void CaptureBuilding::undo (state::State& s, bool notify){
        
    }*/
}