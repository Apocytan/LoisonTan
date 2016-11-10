#include "../state/State.h"
#include "MoveUnit.h"

namespace engine{
    
    MoveUnit::MoveUnit (int index){
        this->index=index;
    }
    void MoveUnit::setCoords (int fdestination_x, int fdestination_y) const{
        fdestination_x = destination_x;
        fdestination_y = destination_y;
        
    }


}