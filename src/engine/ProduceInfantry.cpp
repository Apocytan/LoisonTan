#include "ProduceInfantry.h"
#include "state/MobileElement.h"
#include "state/Infantry.h"
namespace engine{

    ProduceInfantry::ProduceInfantry (int x, int y, state::ElementList* ListOfElements, state::ElementList* ListOfTurn, int playerColor){
        this->x=x;
        this->y=y;
        this->ListOfElements=ListOfElements;
        this->ListOfTurn=ListOfTurn;
        this->playerColor=playerColor;
    }
    
    ProduceInfantry::~ProduceInfantry (){
        
    }
    
    void ProduceInfantry::execute() const{
            // [ On créé son instance]
            state::MobileElement* unit ;
            state::Infantry* soldat = static_cast<state::Infantry*>(unit);
            soldat = new state::Infantry();
            // [ On définit ses statistiques]
            soldat->setSpeed(3);
            soldat->setX(x);
            soldat->setY(y);
            soldat->setPosition(x+y*33); 
            soldat->setRank(0);
            soldat->setHp(10);
            soldat->setDamage(3);
            soldat->setColor(playerColor);
            // [ On ajoute sa tuile ]
            ListOfElements->elements.erase(ListOfElements->elements.begin()+x+y*33);
            ListOfElements->elements.insert(ListOfElements->elements.begin()+x+y*33,soldat);
            ListOfTurn->elements.push_back(soldat);
            std::cout<< "Fighter created" <<std::endl;
    }
   
    
}