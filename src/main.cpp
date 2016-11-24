#include <iostream>

#include <vector>
#include "TileMap.cpp"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../src/engine/Engine.h"
#include "engine/ProduceUnit.h"
#include "../src/state.h"
#include "../src/state/TypeID.h"
#include "engine/BuildCommand.h"
#include "state/ElementList.h"
#include "state/Space.h"
#include "state/Wall.h"
#include "state/Structure.h"
void testSFML() {
        engine::Engine moteur;
        engine::Engine tile;
        
                // Ressources de départ
        int selected=0;
        state::State firstturn;
        state::ElementList* ListOfElements;
        state::ElementList* ListOfUnits;
        state::ElementList* ListOfPlayer;
        state::ElementList* ListOfIa;
        state::Element* elm;
        ListOfElements = new state::ElementList(firstturn);
        ListOfUnits = new state::ElementList(firstturn);
        ListOfPlayer=new state::ElementList(firstturn);
        ListOfIa=new state::ElementList(firstturn);

        /*state::Fighter *avion=new state::Fighter;
        state::Tank *charassaut=new state::Tank;
        state::AntiAir *aa=new state::AntiAir;
        state::Structure *batiment= new state::Structure;*/


	// on crée la fenêtre
	std::string action="rien";
        std::string tileLetter,tileLetter2;
        std::string answer="no";
	sf::RenderWindow window(sf::VideoMode(600, 256), "Tilemap");
        int x=0;
        int y=0;
	// on définit le niveau à l'aide de numéro de tuiles
	std::vector<std::string> level =
	{
		"rF","G","G","G","rF","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G",
		"G","tlR","hR","hR","trR","G","G","G","G","G","G","G","G","G","G","S","G","tlR","hR","hR","hR","hR","hR","hR","trR","G","G","S","G","G","G","G","G",
		"G","vR","rHQ","rM","vR","G","G","G","G","tlR","hR","hR","hR","hR","hR","hR","hR","vR","nF","W","W","G","G","G","vR","S","S","S","S","S","G","G","G",
		"rA","vR","nB","nB","rF","G","G","G","G","vR","nM","S","S","S","W","S","W","vR","W","W","W","W","G","G","vR","S","S","S","S","S","S","G","G",
		"G","blR","hR","hR","hR","hR","hR","hR","hR","brR","W","S","W","W","W","W","nB","vR","G","G","tlR","hR","hR","hR","hR","trR","S","S","S","S","S","S","G",
		"G","G","G","G","G","G","W","vR","W","W","W","W","W","tlR","hR","hR","hR","hR","hR","hR","brR","nB","W","W","W","vR","S","G","S","S","S","G","G",
		"G","G","G","G","G","G","G","vR","W","W","W","W","W","vR","nM","W","G","G","G","vR","S","W","W","W","W","vR","S","G","S","nM","S","G","G",
		"G","G","G","G","G","G","W","vR","W","W","W","W","nB","vR","W","W","G","G","S","vR","S","W","W","W","W","vR","nA","G","G","G","G","G","G",
		"G","G","G","G","G","G","nA","vR","W","W","W","W","S","vR","S","G","G","W","W","vR","nB","W","W","W","W","vR","W","G","G","G","G","G","G",
		"G","G","S","nM","S","G","S","vR","W","W","W","W","S","vR","G","G","G","W","nM","vR","W","W","W","W","W","vR","G","G","G","G","G","G","G",
		"G","G","S","S","S","G","S","vR","W","W","W","nB","tlR","hR","hR","hR","hR","hR","hR","brR","W","W","W","W","W","vR","W","G","G","G","G","G","G",
		"G","S","S","S","S","S","S","blR","hR","hR","hR","hR","brR","G","G","vR","nB","W","W","W","W","S","W","tlR","hR","hR","hR","hR","hR","hR","hR","trR","G",
		"G","G","S","S","S","S","S","S","vR","G","G","W","W","W","W","vR","W","S","W","S","S","S","nM","vR","G","G","G","G","bF","nB","nB","vR","bA",
		"G","G","G","S","S","S","S","S","vR","G","G","G","W","W","nF","vR","hR","hR","hR","hR","hR","hR","hR","brR","G","G","G","G","vR","bM","bHQ","vR","G",
		"G","G","G","G","G","S","G","G","blR","hR","hR","hR","hR","hR","hR","brR","G","S","G","G","G","G","G","G","G","G","G","G","blR","hR","hR","brR","G",
		"G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","bF","G","G","G","bF",
	};

        //Création du deuxième tableau d'éléments
        //state::Element* elemtemp;
        //state::Structure* batiment=static_cast<state::Structure*>(elemtemp);
        //state::Space* espace=static_cast<state::Space*>(elemtemp);
        //state::Wall* mur = static_cast<state::Wall*>(elemtemp);
        for(unsigned int i=0;i<level.size();i++){
            x++;
            if(x==33){
                x=0;
                y++;
            }
            
            
            if(level[i]=="rF" || level[i]=="rA" || level[i]=="rHQ" || level[i]=="rM" || level[i]=="rB"){//structures rouges

                //batiment= new state::Structure;
                //batiment->setColor(2);
                if(level[i]=="rF"){
                    //batiment->setStructureTypeID(state::FACTORY,1);
                    ListOfElements->elements.push_back(new state::Structure(state::FACTORY, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                    
                }
                if(level[i]=="rA"){
                    //batiment->setStructureTypeID(state::AIRPORT,1);
                    ListOfElements->elements.push_back(new state::Structure(state::AIRPORT, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                }
                if(level[i]=="rHQ"){
                    //batiment->setStructureTypeID(state::HEADQUARTER,1);
                    ListOfElements->elements.push_back(new state::Structure(state::HEADQUARTER, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                }
                if(level[i]=="rM"){
                    //batiment->setStructureTypeID(state::MINE,1);
                    ListOfElements->elements.push_back(new state::Structure(state::MINE, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                }
                if(level[i]=="rB"){
                    //batiment->setStructureTypeID(state::BUILDING,1);
                    ListOfElements->elements.push_back(new state::Structure(state::BUILDING, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                }
            }
            if(level[i]=="bF" || level[i]=="bA" || level[i]=="bHQ" || level[i]=="bM" || level[i]=="bB"){//structures bleues

                //batiment= new state::Structure;
                //batiment->setColor(1);
                if(level[i]=="bF"){
                    //batiment->setStructureTypeID(state::FACTORY,1);
                    ListOfElements->elements.push_back(new state::Structure(state::FACTORY, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                   
                }
                if(level[i]=="bA"){
                    //batiment->setStructureTypeID(state::AIRPORT,1);
                    ListOfElements->elements.push_back(new state::Structure(state::AIRPORT, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                }
                if(level[i]=="bHQ"){
                    //batiment->setStructureTypeID(state::HEADQUARTER,1);
                    ListOfElements->elements.push_back(new state::Structure(state::HEADQUARTER, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                }
                if(level[i]=="bM"){
                    //batiment->setStructureTypeID(state::MINE,1);
                    ListOfElements->elements.push_back(new state::Structure(state::MINE, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                }
                if(level[i]=="bB"){
                    //batiment->setStructureTypeID(state::BUILDING,1);
                    ListOfElements->elements.push_back(new state::Structure(state::BUILDING, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                }
            }
            if(level[i]=="nF" || level[i]=="nA"  || level[i]=="nM" || level[i]=="nB"){//structures neutres

                //batiment= new state::Structure;
                //batiment->setColor(0);
                if(level[i]=="nF"){
                    //batiment->setStructureTypeID(state::FACTORY,1);
                    ListOfElements->elements.push_back(new state::Structure(state::FACTORY, 1, 0,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="nA"){
                    //batiment->setStructureTypeID(state::AIRPORT,1);
                    ListOfElements->elements.push_back(new state::Structure(state::AIRPORT, 1, 0,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="nM"){
                    //batiment->setStructureTypeID(state::MINE,1);
                    ListOfElements->elements.push_back(new state::Structure(state::MINE, 1, 0,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="nB"){
                    //batiment->setStructureTypeID(state::BUILDING,1);
                    ListOfElements->elements.push_back(new state::Structure(state::BUILDING, 1, 0,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
            }
            if(level[i]=="vR" || level[i]=="hR" || level[i]=="brR" || level[i]=="blR" || level[i]=="tlR" || level[i]=="trR" || level[i]=="R" || level[i]=="G"){//spaces
                
                if(level[i]=="vR"){
                //    espace= new state::Space(state::verticalROAD);
                    ListOfElements->elements.push_back(new state::Space(state::verticalROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="hR"){
                //    espace= new state::Space(state::horizontalROAD);
                    ListOfElements->elements.push_back(new state::Space(state::horizontalROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="brR"){
                //    espace= new state::Space(state::bottomRightROAD);
                    ListOfElements->elements.push_back(new state::Space(state::bottomRightROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="blR"){
                //    espace= new state::Space(state::bottomLeftROAD);
                    ListOfElements->elements.push_back(new state::Space(state::bottomLeftROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="tlR"){
                //    espace= new state::Space(state::topLeftROAD);
                    ListOfElements->elements.push_back(new state::Space(state::topLeftROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="trR"){
                //    espace= new state::Space(state::TopRightROAD);
                    ListOfElements->elements.push_back(new state::Space(state::TopRightROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="R"){
                //    espace= new state::Space(state::ROAD);
                    ListOfElements->elements.push_back(new state::Space(state::ROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="G"){
                    ListOfElements->elements.push_back(new state::Space(state::GRASS));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
            }
            if(level[i]=="S" || level[i]=="hW" || level[i]=="tW" || level[i]=="lW" || level[i]=="vW" || level[i]=="bW" || level[i]=="rW" || level[i]=="W"){//walls

               
                if(level[i]=="S"){
                    //mur= new state::Wall(state::SEA);
                    ListOfElements->elements.push_back(new state::Wall(state::SEA));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="hW"){
                    //mur= new state::Wall(state::horizontalWater);
                    ListOfElements->elements.push_back(new state::Wall(state::horizontalWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="tW"){
                    //mur= new state::Wall(state::topWater);
                    ListOfElements->elements.push_back(new state::Wall(state::topWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="lW"){
                    //mur= new state::Wall(state::leftWater);
                    ListOfElements->elements.push_back(new state::Wall(state::leftWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="vW"){
                    //mur= new state::Wall(state::verticalWater);
                    ListOfElements->elements.push_back(new state::Wall(state::verticalWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="bW"){
                    //mur= new state::Wall(state::bottomWater);
                    ListOfElements->elements.push_back(new state::Wall(state::bottomWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="rW"){
                    //mur= new state::Wall(state::rightWater);
                    ListOfElements->elements.push_back(new state::Wall(state::rightWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                if(level[i]=="W"){
                    //mur= new state::Wall(state::WOODS);
                    ListOfElements->elements.push_back(new state::Wall(state::WOODS));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
            }
            
        }
        for(unsigned int i=0;i<level.size();i++){
            
            ListOfUnits->elements.push_back(ListOfElements->elements.at(i));
            
        }
        state::MobileElement* me;
        /*me->setDamage(3);
        me->setHp(10);
        me->setSpeed(3);*/
        state::Infantry* inf=static_cast<state::Infantry*>(me);
        inf=new state::Infantry();
        inf->setDamage(3);
        inf->setHp(10);
        inf->setSpeed(3);
        inf->setColor(2);
        inf->setX(2);
        inf->setY(2);
        state::Infantry* inf2=static_cast<state::Infantry*>(me);
        inf2=new state::Infantry();
        inf2->setDamage(3);
        inf2->setHp(10);
        inf2->setSpeed(3);
        inf2->setColor(1);
        inf2->setX(30);
        inf2->setY(13);
        
        ListOfUnits->elements.erase(ListOfUnits->elements.begin()+2+2*33);
        ListOfUnits->elements.insert(ListOfUnits->elements.begin()+2+2*33,inf);
        ListOfUnits->elements.erase(ListOfUnits->elements.end()-(2+2*33+1));
        ListOfUnits->elements.insert(ListOfUnits->elements.end()-(2+2*33),inf2);
	// on crée la tilemap avec le niveau précédemment défini
	TileMap map;
        std::vector<std::string> levelwUnit=level;
        levelwUnit[5]="rinfantry";
	if (!map.load("res/Textures.png", sf::Vector2u(16, 16), ListOfUnits, 33, 16))
		std::cout << "an error occured" << std::endl;
        sf::Event event;
        
            // [Boucle principale pour l'affichage]
	while (window.isOpen())
	{
		// [Gestion des événements]
		while (window.pollEvent(event))
		{
                    /*state::Structure* rHq=static_cast<state::Structure*>(ListOfUnits->elements.at(2+2*33));
                    state::Structure* bHq=static_cast<state::Structure*>(ListOfUnits->elements.at(30+13*33));
                    if(rHq->getColor()== bHq->getColor()){
                        std::cout<<"la partie est terminée"<<std::endl;
                        window.close();
                    }*/
			if (event.type == sf::Event::Closed){
				window.close();}

			if (event.type == sf::Event::MouseButtonPressed) {
                            if(event.type==sf::Event::MouseButtonPressed){    
                                if (event.mouseButton.button == sf::Mouse::Left) {
                                            // [Récupération de la tuile initiale]
                                    x = event.mouseButton.x;
                                    y= event.mouseButton.y;
                                    x=x/16;
                                    y=y/16;
                                    //tileLetter=levelwUnit[x+y*33];
                                    std::cout << "Got your tile : " << x << "," <<y<< "," /*<< tileLetter*/ << std::endl;
                                    ListOfUnits->elements.at(x+y*33)->setX(x);
                                    ListOfUnits->elements.at(x+y*33)->setY(y);
                                    elm=ListOfUnits->elements.at(x+y*33);
                                    selected=1;
                                    if(elm->getTypeID()==state::TypeID::STRUCTURE){
                                        state::Structure* elms=static_cast<state::Structure*>(elm);
                                        if(elms->getStructureTypeID()==state::StructureTypeID::AIRPORT){
                                            std::cout<<"je produis un fighter"<<std::endl;
                                            moteur.ProduceFighter(x,y,ListOfUnits,ListOfPlayer,2);
                                        }
                                        if(elms->getStructureTypeID()==state::StructureTypeID::FACTORY){
                                            std::cout<<"je produis une infrantrie"<<std::endl;
                                            moteur.ProduceInfantry(x,y,ListOfUnits,ListOfPlayer,2);
                                        }
                                        if (!map.load("res/Textures.png", sf::Vector2u(16, 16), ListOfUnits, 33, 16)) {
							std::cout << "an error occured" << std::endl;
                                        }
                                    }
                                    
                                             
				}
                                
                            }
				if (event.mouseButton.button == sf::Mouse::Right) {
                                    if(selected==1){
                                        
                                        x = event.mouseButton.x;
                                        y= event.mouseButton.y;
                                        x=x/16;
                                        y=y/16;
                                    //tileLetter=levelwUnit[x+y*33];
                                        std::cout << "Got your tile : " << x << "," <<y<< "," /*<< tileLetter*/ << std::endl;
                                        ListOfUnits->elements.at(x+y*33)->setX(x);
                                        ListOfUnits->elements.at(x+y*33)->setY(y);
                                        state::Element* eld=ListOfUnits->elements.at(x+y*33);
                                        if(eld->getTypeID()==state::TypeID::SPACE ){
                                            moteur.MoveUnit(elm,eld,ListOfElements,ListOfUnits);
                                        }
                                        if(eld->getTypeID()==state::TypeID::STRUCTURE){
                                            state::Structure* sd=static_cast<state::Structure*>(eld);
                                            state::MobileElement* sm=static_cast<state::MobileElement*>(elm);
                                            if(sd->getColor()==sm->getColor()){
                                                moteur.MoveUnit(elm,eld,ListOfElements,ListOfUnits);
                                            }else{
                                                if(sm->getTypeID()==state::INFANTRY){
                                                    std::cout << "Capturer ? y or n" <<std::endl;
                                                    std::cin >> answer;
                                                    if(answer=="y"){
                                                        state::Infantry* infm=static_cast<state::Infantry*>(sm);
                                                        state::Structure* toBeCaptured=static_cast<state::Structure*>(eld);
                                                        std::cout<<"capture!"<<std::endl;
                                                        moteur.CaptureEnemy(infm,toBeCaptured);
                                                    }
                                                }else{
                                                    std::cout<<"seul les infantries peuvent capturer!"<<std::endl;
                                                }
                                            }
                                        }
                                        if(eld->getTypeID()==state::TypeID::ANTIAIR || eld->getTypeID()==state::TypeID::FIGHTER || eld->getTypeID()==state::TypeID::INFANTRY || eld->getTypeID()==state::TypeID::TANK){
                                            std::cout<<"on attaque"<<std::endl;
                                            moteur.AttackEnemy(elm,eld,ListOfElements,ListOfUnits);
                                        }
                                        if (!map.load("res/Textures.png", sf::Vector2u(16, 16), ListOfUnits, 33, 16)) {
							std::cout << "an error occured" << std::endl;
						}
                                        selected=0;
                                    }else{std::cout<<"aucune unité sélectionné"<<std::endl;}
					
                                        
				}
                        }
			
		}
		// on dessine le niveau
		window.clear();
		window.draw(map);
		window.display();
        }
}

// Fin test SFML

#include "state.hpp"

using namespace std;
using namespace state;



int main() {
	testSFML();
               
	return 0;
}
