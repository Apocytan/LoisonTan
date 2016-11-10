#include <iostream>

#include "TileMap.cpp"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../src/engine/Engine.h"
#include "engine/ProduceUnit.h"
#include "../src/state.h"
#include "../src/state/TypeID.h"

void testSFML() {
                // Variable de récupération des données d'une tuile
        int tileX=0;
        int tileY=0;
        engine::Engine tile;
        
                // Ressources de départ
        state::State firstturn;
        firstturn.setIron(10000);
        
        //erreur ici //state::MobileElement *unitkind = new state::MobileElement;
        state::MobileElement *unitkind(0);
        state::Structure buildingkind;
        


        // liste des actions
        //création d'une règle
        //engine::Ruler rule;
        engine::Action *produire;
	// on crée la fenêtre
        // test d'une production
        //state::Infantry soldat= new state::Infantry();
        state::TypeID soldier = state::TypeID::INFANTRY;
        
        
        //soldat =new state::Infantry;
       
        //unitkind->setTypeID(soldier);

        std::cout << unitkind << std::endl;
        
	bool selected=0;
        std::string tileLetter;
	sf::RenderWindow window(sf::VideoMode(600, 256), "Tilemap");
        int x,y;
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

	// on crée la tilemap avec le niveau précédemment défini
	TileMap map;
        std::vector<std::string> levelwUnit=level;
        levelwUnit[0]="rfighter";
	if (!map.load("res/Textures.png", sf::Vector2u(16, 16), levelwUnit, 33, 16))
		std::cout << "an error occured" << std::endl;
        sf::Event event;
	// on fait tourner la boucle principale
	while (window.isOpen())
	{
		// on gère les évènements
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();}

			if (event.type == sf::Event::MouseButtonPressed) {
                            if(event.type==sf::Event::MouseButtonPressed){    
                                if (event.mouseButton.button == sf::Mouse::Left) {
                                            //Récupération des données de la tuile
					tileX=tile.TakeEventX(event);
                                        tileY=tile.TakeEventY(event); 
                                        tileLetter=tile.TakeEventTile(levelwUnit,tileX,tileY);
                                        std::cout << "Got your tile : " << tileX << "," <<tileY<< "," << tileLetter << std::endl;
                                        
                                        if (tileLetter == "rA" ){
                                            std::cout << "You have selectionned a building : Aiport, click another time to build" << std::endl;
                                            //rule.produce(firstturn,buildingkind,unitkind);
                                            //state::MobileElement *unitkind = dynamic_cast<state::Infantry*> (soldat); 
                                            //unitkind->setTypeID(soldat->getTypeID());
                                            
                                            //engine::ProduceUnit(tileX,tileY,unitkind);
                                            tileLetter = "rF";
                                        }
                                        if (tileLetter == "bA" ){
                                            std::cout << "You have selectionned a building : Aiport " << std::endl;

                                        }
                                        if (tileLetter == "rF" || tileLetter=="bF"){
                                            std::cout << "You have selectionned a building : Factory " << std::endl;
                                        }
					if (tileLetter == "rfighter" || tileLetter == "rinfantry" || tileLetter == "rtank" || tileLetter == "rantiair") {
						selected = 1;
                                                //je passe selected à 1 avec l'élément sauvegardé
					}
					else {
						std::cout << "The selected unit is not mobile, please select another" << std::endl;
					}
				}
                            }
				if (event.mouseButton.button == sf::Mouse::Right) {
					if (selected == 1) {
                                                //je déplace mon élément
						x = event.mouseButton.x;
						y = event.mouseButton.y;
						x = x / 16;
						y = y / 16;
                                                levelwUnit=level;
                                                levelwUnit[x+y*33]=tileLetter;
						if (!map.load("res/Textures.png", sf::Vector2u(16, 16), levelwUnit, 33, 16)) {
							std::cout << "an error occured" << std::endl;
						}
						
						selected = 0;
					}
					else {
						std::cout << "no mobile unit is currently selected" << std::endl;
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
