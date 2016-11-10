#include "CaptureBuilding.h"

namespace engine {
    CaptureBuilding::CaptureBuilding (int x, int y, state::Structure BuildingType){
        this-> x = x;
        this->y = y;
        this->BuildingType = BuildingType;
     }
    /*void CaptureBuilding::apply (state::State& s, bool notify){
        
    }
    void CaptureBuilding::undo (state::State& s, bool notify){
        
    }*/
}