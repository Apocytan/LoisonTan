#include "DumbIA.h"
#include "../src/state/TypeID.h"

namespace ia{
    DumbIA::DumbIA (state::State* mainState, engine::Engine* mainEngine){
        
    }
    void DumbIA::dumbMove (state::ElementList* ListOfElements, state::ElementList* ListOfUnits, state::ElementList* ListOfIa, engine::Engine* moteur){
        int dir=0;
        int i=0;
        int x=ListOfIa->elements.at(i)->getX();
        int y=ListOfIa->elements.at(i)->getX();
        state::Element* eld;
        state::Element* elm=ListOfUnits->elements.at(x+y*33);
        if(elm->isStatic()==false){
            if(ListOfIa->elements.at(i-1)->getTypeID()==state::TypeID::WALL){
                dir=1;
            }
            if(dir==0){
                eld=ListOfUnits->elements.at(x-1+y*33);
                
            }else{
                eld=ListOfUnits->elements.at(x+1+y*33);
            }
            //moteur->MoveUnit(elm,eld,ListOfElements,ListOfUnits);
        }
        
    }
    
}