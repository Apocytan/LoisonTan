#include "ProduceFighter.h"
#include "state/Fighter.h"
#include "state/MobileElement.h"
namespace engine{

    ProduceFighter::ProduceFighter (int x, int y, state::ElementList* ListOfElements, state::ElementList* ListOfTurn, int playerColor){
        this->x=x;
        this->y=y;
        this->ListOfElements=ListOfElements;
        this->ListOfTurn=ListOfTurn;
        this->playerColor=playerColor;
    }
    
    ProduceFighter::~ProduceFighter (){
        
    }
    
    void ProduceFighter::execute () const{
            // [ On créé son instance]
            state::MobileElement* unit ;
            state::Fighter* avion = static_cast<state::Fighter*>(unit);
            avion = new state::Fighter();
            // [ On définit ses statistiques]
            avion->setSpeed(5);
            avion->setX(x);
            avion->setY(y);
            avion->setPosition(x+y*33); 
            avion->setRank(0);
            avion->setHp(10);
            avion->setDamage(3);
            avion->setColor(playerColor);
            // [ On ajoute sa tuile ]
            ListOfElements->elements.erase(ListOfElements->elements.begin()+x+y*33);
            ListOfElements->elements.insert(ListOfElements->elements.begin()+x+y*33,avion);
            ListOfTurn->elements.push_back(avion);
            std::cout<< "Fighter created" <<std::endl;
    }
    
}