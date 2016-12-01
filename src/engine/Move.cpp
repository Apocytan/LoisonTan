#include "Move.h"
#include "state/MobileElement.h"

namespace engine{
    
    Move::Move (state::Element* mover, state::Element* destination, state::ElementList* StaticMapElements, state::ElementList* MapUnits){
        this->mover=mover;
        this->destination=destination;
        this->StaticMapElements=StaticMapElements;
        this->MapUnits=MapUnits;
    }
    
    Move::~Move (){
        
    }
    
    void Move::execute () const{
        if(mover->isStatic()!=1 && destination->isStatic()==1){
            int mx=mover->getX();
            int my=mover->getY();
            mover->setX(destination->getX());
            mover->setY(destination->getY());
            
            int dx=destination->getX();
            int dy=destination->getY();


            state::MobileElement* first=static_cast<state::MobileElement*>(mover);
            int distance = abs((dx-mx)+(dy-my));
            if (distance > first->getSpeed()){
                std::cout << "La case ciblée est trop éloignée" << std::endl;
                std::cout << "Rappel : Infantry[3] / Fighter[5]" << std::endl;
            }else{
                mover->setX(dx);
                mover->setY(dy);
                MapUnits->elements.erase(MapUnits->elements.begin()+dx+dy*33);                                          //on efface l'élément de destination
                MapUnits->elements.insert(MapUnits->elements.begin()+dx+dy*33,mover);                                   //on le remplace par l'élément que l'on bouge
                MapUnits->elements.erase(MapUnits->elements.begin()+mx+my*33);                                          //on efface l'élément de départ
                MapUnits->elements.insert(MapUnits->elements.begin()+mx+my*33,StaticMapElements->elements.at(mx+my*33));//on insert l'élément issus de la map où se trouvait notre unité         
                std::cout << "Vous êtes arrivée à destination" << std::endl;
            }
        }else{
        std::cout<<"Votre unité n'est pas déplaçable"<<std::endl;
        }
    }
}