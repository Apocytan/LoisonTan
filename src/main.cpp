#include <iostream>

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
void testSFML() {
        engine::Engine moteur;
        engine::Engine tile;
        
                // Ressources de départ

        state::State firstturn;
        firstturn.setIron(10000);
        state::ElementList* ListOfElements;
        ListOfElements = new state::ElementList(firstturn);
                // déclarations et instanciation des variables("unités") de production et d'attaque
        state::Infantry *soldat=new state::Infantry;
        state::Fighter *avion = new state::Fighter;
        state::Structure *toCapture=new state::Structure;
        state::Infantry *capturer=new state::Infantry;
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
        int x2=0;
        int y2=0;
        int choix=0;
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
            
            if(level[i]=="rF" || level[i]=="rA" || level[i]=="rHQ" || level[i]=="rM" || level[i]=="rB"){//structures rouges

                //batiment= new state::Structure;
                //batiment->setColor(2);
                if(level[i]=="rF"){
                    //batiment->setStructureTypeID(state::FACTORY,1);
                    ListOfElements->elements.push_back(new state::Structure(state::FACTORY, 1, 2));
                }
                if(level[i]=="rA"){
                    //batiment->setStructureTypeID(state::AIRPORT,1);
                    ListOfElements->elements.push_back(new state::Structure(state::AIRPORT, 1, 2));
                }
                if(level[i]=="rHQ"){
                    //batiment->setStructureTypeID(state::HEADQUARTER,1);
                    ListOfElements->elements.push_back(new state::Structure(state::HEADQUARTER, 1, 2));
                }
                if(level[i]=="rM"){
                    //batiment->setStructureTypeID(state::MINE,1);
                    ListOfElements->elements.push_back(new state::Structure(state::MINE, 1, 2));
                }
                if(level[i]=="rB"){
                    //batiment->setStructureTypeID(state::BUILDING,1);
                    ListOfElements->elements.push_back(new state::Structure(state::BUILDING, 1, 2));
                }
            }
            if(level[i]=="bF" || level[i]=="bA" || level[i]=="bHQ" || level[i]=="bM" || level[i]=="bB"){//structures bleues

                //batiment= new state::Structure;
                //batiment->setColor(1);
                if(level[i]=="bF"){
                    //batiment->setStructureTypeID(state::FACTORY,1);
                    ListOfElements->elements.push_back(new state::Structure(state::FACTORY, 1, 1));
                }
                if(level[i]=="bA"){
                    //batiment->setStructureTypeID(state::AIRPORT,1);
                    ListOfElements->elements.push_back(new state::Structure(state::AIRPORT, 1, 1));
                }
                if(level[i]=="bHQ"){
                    //batiment->setStructureTypeID(state::HEADQUARTER,1);
                    ListOfElements->elements.push_back(new state::Structure(state::HEADQUARTER, 1, 1));
                }
                if(level[i]=="bM"){
                    //batiment->setStructureTypeID(state::MINE,1);
                    ListOfElements->elements.push_back(new state::Structure(state::MINE, 1, 1));
                }
                if(level[i]=="bB"){
                    //batiment->setStructureTypeID(state::BUILDING,1);
                    ListOfElements->elements.push_back(new state::Structure(state::BUILDING, 1, 1));
                }
            }
            if(level[i]=="nF" || level[i]=="nA"  || level[i]=="nM" || level[i]=="nB"){//structures neutres

                //batiment= new state::Structure;
                //batiment->setColor(0);
                if(level[i]=="nF"){
                    //batiment->setStructureTypeID(state::FACTORY,1);
                    ListOfElements->elements.push_back(new state::Structure(state::FACTORY, 1, 0));
                }
                if(level[i]=="nA"){
                    //batiment->setStructureTypeID(state::AIRPORT,1);
                    ListOfElements->elements.push_back(new state::Structure(state::AIRPORT, 1, 0));
                }
                if(level[i]=="nM"){
                    //batiment->setStructureTypeID(state::MINE,1);
                    ListOfElements->elements.push_back(new state::Structure(state::MINE, 1, 0));
                }
                if(level[i]=="nB"){
                    //batiment->setStructureTypeID(state::BUILDING,1);
                    ListOfElements->elements.push_back(new state::Structure(state::BUILDING, 1, 0));
                }
            }
            if(level[i]=="vR" || level[i]=="hR" || level[i]=="brR" || level[i]=="blR" || level[i]=="tlR" || level[i]=="trR" || level[i]=="R" || level[i]=="G"){//spaces
                
                if(level[i]=="vR"){
                //    espace= new state::Space(state::verticalROAD);
                    ListOfElements->elements.push_back(new state::Space(state::verticalROAD));
                }
                if(level[i]=="hR"){
                //    espace= new state::Space(state::horizontalROAD);
                    ListOfElements->elements.push_back(new state::Space(state::horizontalROAD));
                }
                if(level[i]=="brR"){
                //    espace= new state::Space(state::bottomRightROAD);
                    ListOfElements->elements.push_back(new state::Space(state::bottomRightROAD));
                }
                if(level[i]=="blR"){
                //    espace= new state::Space(state::bottomLeftROAD);
                    ListOfElements->elements.push_back(new state::Space(state::bottomLeftROAD));
                }
                if(level[i]=="tlR"){
                //    espace= new state::Space(state::topLeftROAD);
                    ListOfElements->elements.push_back(new state::Space(state::topLeftROAD));
                }
                if(level[i]=="trR"){
                //    espace= new state::Space(state::TopRightROAD);
                    ListOfElements->elements.push_back(new state::Space(state::TopRightROAD));
                }
                if(level[i]=="R"){
                //    espace= new state::Space(state::ROAD);
                    ListOfElements->elements.push_back(new state::Space(state::ROAD));
                }
                if(level[i]=="G"){
                    ListOfElements->elements.push_back(new state::Space(state::GRASS));
                }
            }
            if(level[i]=="S" || level[i]=="hW" || level[i]=="tW" || level[i]=="lW" || level[i]=="vW" || level[i]=="bW" || level[i]=="rW" || level[i]=="W"){//walls

               
                if(level[i]=="S"){
                    //mur= new state::Wall(state::SEA);
                    ListOfElements->elements.push_back(new state::Wall(state::SEA));
                }
                if(level[i]=="hW"){
                    //mur= new state::Wall(state::horizontalWater);
                    ListOfElements->elements.push_back(new state::Wall(state::horizontalWater));
                }
                if(level[i]=="tW"){
                    //mur= new state::Wall(state::topWater);
                    ListOfElements->elements.push_back(new state::Wall(state::topWater));
                }
                if(level[i]=="lW"){
                    //mur= new state::Wall(state::leftWater);
                    ListOfElements->elements.push_back(new state::Wall(state::leftWater));
                }
                if(level[i]=="vW"){
                    //mur= new state::Wall(state::verticalWater);
                    ListOfElements->elements.push_back(new state::Wall(state::verticalWater));
                }
                if(level[i]=="bW"){
                    //mur= new state::Wall(state::bottomWater);
                    ListOfElements->elements.push_back(new state::Wall(state::bottomWater));
                }
                if(level[i]=="rW"){
                    //mur= new state::Wall(state::rightWater);
                    ListOfElements->elements.push_back(new state::Wall(state::rightWater));
                }
                if(level[i]=="W"){
                    //mur= new state::Wall(state::WOODS);
                    ListOfElements->elements.push_back(new state::Wall(state::WOODS));
                }
            }
            }

	// on crée la tilemap avec le niveau précédemment défini
	TileMap map;
        std::vector<std::string> levelwUnit=level;
        levelwUnit[5]="rinfantry";
	if (!map.load("res/Textures.png", sf::Vector2u(16, 16), ListOfElements, 33, 16))
		std::cout << "an error occured" << std::endl;
        sf::Event event;
        
            // [Boucle principale pour l'affichage]
	while (window.isOpen())
	{
		// [Gestion des événements]
		while (window.pollEvent(event))
		{
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
                                    tileLetter=levelwUnit[x+y*33];
                                    std::cout << "Got your tile : " << x << "," <<y<< "," << tileLetter << std::endl;
                                             // [Choix Action]
                                        if (tileLetter=="rfighter" || tileLetter == "rtank" || tileLetter == "rantiair" || tileLetter == "bfighter" || tileLetter =="btank" || tileLetter == "bantiair"){
                                            std::cout << "Que souhaitez vous faire, 0 pour ne rien faire, 1 pour bouger, 2 pour aller attaquer" << std::endl;
                                            std::cin >> choix;
                                            if (choix==0) action ="rien";
                                            if (choix==1) action ="bouger";
                                            if (choix==2) action ="attaquer";
                                            std::cout << "Vous souhaitez " << action << std::endl;
                                        }
                                        if(tileLetter == "rinfantry" || tileLetter == "binfantry"){
                                            std::cout << "Que souhaitez vous faire, 0 pour ne rien faire, 1 pour bouger, 2 pour aller attaquer, 3 pour aller capturer" << std::endl;
                                            std::cin >> choix;
                                            if (choix==0) action ="rien";
                                            if (choix==1) action ="bouger";
                                            if (choix==2) action ="attaquer";
                                            if (choix==3) { 
                                                action ="capturer";
                                                capturer->setX(x);
                                                capturer->setY(y);
                                            }
                                            std::cout << "Vous souhaitez " << action << std::endl;
                                        }
                                                // [Production d'infantry]
                                        if (tileLetter=="rF" || tileLetter == "bF"){
                                           if (event.mouseButton.button == sf::Mouse::Left){
                                               //std::cout << "Build Infantry 'yes' or 'no' ?" <<std::endl;
                                               //std::cin >> answer;
                                               //if (answer=="yes") {
                                                   moteur.ProduceInfantry(x,y,soldat,ListOfElements); 
                                                //   answer = "no";
                                                //}
                                            }
                                        }       // [Production d'avion]
                                            if (tileLetter=="rA" || tileLetter == "bA"){
                                                if (event.mouseButton.button == sf::Mouse::Left){
                                               //std::cout << "Build fighter 'yes' or 'no' ?" <<std::endl;
                                               //std::cin >> answer;
                                               //if (answer=="yes") {
                                                   moteur.ProduceFighter(x,y,avion,ListOfElements);
                                                //   answer = "no";
                                                //}
                                            }
                                        }
				}
                            }
				if (event.mouseButton.button == sf::Mouse::Right) {
					if (action == "bouger") {
						x2 = event.mouseButton.x;
						y2 = event.mouseButton.y;
						x2 = x2 / 16;
						y2 = y2 / 16;
                                                levelwUnit=level;
                                                levelwUnit[x2+y2*33]=tileLetter;
                                                //moteur.MoveUnit(elem,x2,y2);
						if (!map.load("res/Textures.png", sf::Vector2u(16, 16), ListOfElements, 33, 16)) {
							std::cout << "an error occured" << std::endl;
						}
						
						action = "rien";
					}
                                        if (action == "capturer") {
                                            printf("Selectionnez la cible à capturer ! \n");
                                            x2 = event.mouseButton.x;
                                            y2 = event.mouseButton.y;
                                            x2 = x2 / 16;
                                            y2 = y2 / 16;
                                            tileLetter2=levelwUnit[x2+(y2)*33];
                                            std::cout << "Vous voulez capturer: " << x2 << "," <<y2<< "," << tileLetter2 << std::endl;
                                            toCapture->setX(x2);
                                            toCapture->setY(y2);
                                            moteur.CaptureEnemy(capturer,toCapture);
                                            // [ l'unité se déplace aussi à la case sélectionnée]
                                            action = "rien";
					}
                                        if (action == "attaquer") {
                                            printf("Selectionnez la cible à attaquer ! \n");
                                            x2 = event.mouseButton.x;
                                            y2 = event.mouseButton.y;
                                            x2 = x2 / 16;
                                            y2 = y2 / 16;
                                            levelwUnit=level;
                                            std::cout << "Votre unité en " << x << " "<< y << " souhaite attaquer celle en " << x2 << " " << y2 << std::endl;
                                            moteur.AttackEnemy(ListOfElements->elements.at(x+y*33),ListOfElements->elements.at(x2+y2*33));
                                            
					action = "rien";
					}
                                        
				}
                        }
			/*}*/
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
