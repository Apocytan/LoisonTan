#include <iostream>
#include <SFML/Network/../Window/Keyboard.hpp>
#include <vector>
#include "TileMap.cpp"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../src/engine/Engine.h"
#include "../src/state.h"
#include "../src/state/TypeID.h"
#include "state/ElementList.h"
#include "state/Space.h"
#include "state/Wall.h"
#include "state/Structure.h"
#include "engine/Command.h"
#include "engine/ProduceFighterCommand.h"
#include "engine/ProduceInfantryCommand.h"
#include "engine/CaptureCommand.h"
#include "engine/AttackCommand.h"
#include "engine/MoveCommand.h"
void testSFML() {
        std::cout << "     _________________________________________________________________" << std::endl;
        std::cout << "    |                                                                 |" << std::endl;
        std::cout << "    |  Bienvenue sur ''Advance Wars'' par Alexis LOISON et Eric TAN   |" << std::endl;
        std::cout << "    |    Pour terminer votre tour appuyer sur ESPACE puis validez     |" << std::endl;
        std::cout << "    |_________________________________________________________________|" << std::endl;
                // instanciation de la liste des commandes
        std::vector<engine::Command*> listecommandes;
        std::vector<engine::Action*> listeactions;
        engine::CommandSet* gamecmd;
        gamecmd = new engine::CommandSet(listecommandes);
        engine::ActionList* gameact;
        gameact=new engine::ActionList(listeactions);
        engine::Engine* moteur;
        moteur=new engine::Engine(gamecmd,gameact);
        std::mutex render_mutex;
        
                // instanciation de la liste des actions
       /* std::vector<engine::Action*> listeactions;
        engine::ActionList* gameact;
        gameact = new engine::ActionList(listeactions);
        */
       // engine::Engine moteur(gamecmd,gameact);
        
                // [Déclaration des différentes listes utilisées]
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
        // J0 : neutre, J1 : bleu, J2 : rouge
        int playercolor=2;  
	sf::RenderWindow window(sf::VideoMode(600, 256), "Tilemap"); // création de la fenêtre
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

        for(unsigned int i=0;i<level.size();i++){
            x++;
            if(x==33){
                x=0;
                y++;
            }
            
            // [Rajout des structures rouges]
            if(level[i]=="rF" || level[i]=="rA" || level[i]=="rHQ" || level[i]=="rM" || level[i]=="rB"){

                if(level[i]=="rF"){
                    ListOfElements->elements.push_back(new state::Structure(state::FACTORY, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                    
                }
                if(level[i]=="rA"){
                    ListOfElements->elements.push_back(new state::Structure(state::AIRPORT, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                }
                if(level[i]=="rHQ"){
                    ListOfElements->elements.push_back(new state::Structure(state::HEADQUARTER, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                }
                if(level[i]=="rM"){
                    ListOfElements->elements.push_back(new state::Structure(state::MINE, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                }
                if(level[i]=="rB"){
                    ListOfElements->elements.push_back(new state::Structure(state::BUILDING, 1, 2,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfPlayer->elements.push_back(ListOfElements->elements.at(i));
                }
            }
            // [Rajout des structures bleues]
            if(level[i]=="bF" || level[i]=="bA" || level[i]=="bHQ" || level[i]=="bM" || level[i]=="bB"){
                
                if(level[i]=="bF"){
                    ListOfElements->elements.push_back(new state::Structure(state::FACTORY, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                }
                
                if(level[i]=="bA"){
                    ListOfElements->elements.push_back(new state::Structure(state::AIRPORT, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                }
                
                if(level[i]=="bHQ"){
                    ListOfElements->elements.push_back(new state::Structure(state::HEADQUARTER, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                }
                
                if(level[i]=="bM"){
                    ListOfElements->elements.push_back(new state::Structure(state::MINE, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                }
                
                if(level[i]=="bB"){
                    ListOfElements->elements.push_back(new state::Structure(state::BUILDING, 1, 1,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                    ListOfIa->elements.push_back(ListOfElements->elements.at(i));
                }
            }
            
            // [Rajout des structures neutres]
            if(level[i]=="nF" || level[i]=="nA"  || level[i]=="nM" || level[i]=="nB"){//structures neutres

                if(level[i]=="nF"){
                    ListOfElements->elements.push_back(new state::Structure(state::FACTORY, 1, 0,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="nA"){
                    ListOfElements->elements.push_back(new state::Structure(state::AIRPORT, 1, 0,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="nM"){
                    ListOfElements->elements.push_back(new state::Structure(state::MINE, 1, 0,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="nB"){
                    ListOfElements->elements.push_back(new state::Structure(state::BUILDING, 1, 0,20));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
            }
            
            // [Rajout des "space"]
            if(level[i]=="vR" || level[i]=="hR" || level[i]=="brR" || level[i]=="blR" || level[i]=="tlR" || level[i]=="trR" || level[i]=="R" || level[i]=="G"){
                
                if(level[i]=="vR"){
                    ListOfElements->elements.push_back(new state::Space(state::verticalROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="hR"){
                    ListOfElements->elements.push_back(new state::Space(state::horizontalROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="brR"){
                    ListOfElements->elements.push_back(new state::Space(state::bottomRightROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="blR"){
                    ListOfElements->elements.push_back(new state::Space(state::bottomLeftROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="tlR"){
                    ListOfElements->elements.push_back(new state::Space(state::topLeftROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="trR"){
                    ListOfElements->elements.push_back(new state::Space(state::TopRightROAD));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="R"){
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
            
            // [Rajout des "wall"]
            if(level[i]=="S" || level[i]=="hW" || level[i]=="tW" || level[i]=="lW" || level[i]=="vW" || level[i]=="bW" || level[i]=="rW" || level[i]=="W"){

                if(level[i]=="S"){
                    ListOfElements->elements.push_back(new state::Wall(state::SEA));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="hW"){
                    ListOfElements->elements.push_back(new state::Wall(state::horizontalWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="tW"){
                    ListOfElements->elements.push_back(new state::Wall(state::topWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="lW"){
                    ListOfElements->elements.push_back(new state::Wall(state::leftWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="vW"){
                    ListOfElements->elements.push_back(new state::Wall(state::verticalWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="bW"){
                    ListOfElements->elements.push_back(new state::Wall(state::bottomWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="rW"){
                    ListOfElements->elements.push_back(new state::Wall(state::rightWater));
                    ListOfElements->elements.at(i)->setX(x);
                    ListOfElements->elements.at(i)->setY(y);
                }
                
                if(level[i]=="W"){
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
        ListOfPlayer->elements.push_back(inf);
        ListOfIa->elements.push_back(inf2);
	// on crée la tilemap avec le niveau précédemment défini
	TileMap map;
        std::vector<std::string> levelwUnit=level;
        levelwUnit[5]="rinfantry";
	if (!map.load("res/Textures.png", sf::Vector2u(16, 16), ListOfUnits, 33, 16))
		std::cout << "an error occured" << std::endl;
        sf::Event event;
        std::cout << "Au joueur Rouge de jouer " << std::endl;
        
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
                        
                        // Jeu à tour de rôle
                        if (event.type==sf::Event::KeyPressed){
                            
                            if(event.key.code==sf::Keyboard::Space){
                                
                                if(playercolor==1){
                                    
                                    playercolor++;
                                }
                                else{
                                    
                                    playercolor--;
                                }
                                if(playercolor==1)
                                    std::cout << "Au joueur Bleu de jouer " << std::endl;
                                if(playercolor==2)
                                    std::cout << "Au joueur Rouge de jouer " << std::endl;
                            }
                        }
                        
			if (event.type == sf::Event::MouseButtonPressed) {
                            if(event.type==sf::Event::MouseButtonPressed){    
                                if (event.mouseButton.button == sf::Mouse::Left) {
                                    
                                    // [Récupération de la tuile initiale] 
                                    //render_mutex.lock();
                                    x=event.mouseButton.x;
                                    y=event.mouseButton.y;
                                    x=x/16;
                                    y=y/16;
                                    std::cout << "Tuile sélectionnée : " << x << "," <<y<<std::endl;
                                    ListOfUnits->elements.at(x+y*33)->setX(x);
                                    ListOfUnits->elements.at(x+y*33)->setY(y);
                                    elm=ListOfUnits->elements.at(x+y*33);
                                    if(elm->getTypeID()!=state::TypeID::SPACE || elm->getTypeID()!=state::TypeID::WALL){
                                        if(!elm->isStatic()){
                                            state::MobileElement* elmm=static_cast<state::MobileElement*>(elm);
                                            if(elmm->getColor()==playercolor){
                                                selected=1;
                                            }else{
                                                std::cout<<"cette unité ne vous appartient pas"<<std::endl;
                                            }
                                        }
                                    }else{std::cout<<"l'élément sélectionné n'est pas contrôlable"<<std::endl;}
                                    
                                    
                                    if(elm->getTypeID()==state::TypeID::STRUCTURE){
                                        state::Structure* elms=static_cast<state::Structure*>(elm);
                                        if(elms->getStructureTypeID()==state::StructureTypeID::AIRPORT){
                                            
                                            if (playercolor == elms->getColor()){
                                                std::cout<<"Commande de production d'un fighter enregistrée"<<std::endl;
                                                if(playercolor==2){
                                                    moteur->addCommand(new engine::ProduceFighterCommand(x,y,ListOfUnits,ListOfPlayer,playercolor));
                                                }else{
                                                    moteur->addCommand(new engine::ProduceFighterCommand(x,y,ListOfUnits,ListOfIa,playercolor));
                                                }
                                                
                                                moteur->apply();
                                                moteur->run();
                                                //render_mutex.unlock();
                                            }
                                            else{
                                                std::cout<<"Ceci ne vous appartient pas !"<<std::endl;
                                            }
                                            
                                        }
                                        
                                        if(elms->getStructureTypeID()==state::StructureTypeID::FACTORY){
                                            if (playercolor == elms->getColor()){
                                                std::cout<<"Commande de production d'une infantrie enregistrée"<<std::endl;
                                                if(playercolor==2){
                                                    moteur->addCommand(new engine::ProduceInfantryCommand(x,y,ListOfUnits,ListOfPlayer,playercolor));
                                                }else{
                                                    moteur->addCommand(new engine::ProduceInfantryCommand(x,y,ListOfUnits,ListOfIa,playercolor));
                                                }
                                                moteur->apply();
                                                moteur->run();
                                                //render_mutex.unlock();
                                            }
                                            else{
                                                std::cout<<"Ceci ne vous appartient pas !"<<std::endl;
                                            }
                                        }
                                        //render_mutex.lock();
                                        if (!map.load("res/Textures.png", sf::Vector2u(16, 16), ListOfUnits, 33, 16)) {//inutile de faire un raffraichissement si il n'y a pas de changement d'état
							std::cout << "an error occured" << std::endl;
                                        }
                                        //render_mutex.unlock();
                                    }        
				}
                            }
				if (event.mouseButton.button == sf::Mouse::Right) {
                                    if(selected==1){
                                        x = event.mouseButton.x;
                                        y= event.mouseButton.y;
                                        x=x/16;
                                        y=y/16;
                                        std::cout << "Tuile sélectionnée : " << x << "," <<y<<std::endl;
                                        ListOfUnits->elements.at(x+y*33)->setX(x);
                                        ListOfUnits->elements.at(x+y*33)->setY(y);
                                        state::Element* eld=ListOfUnits->elements.at(x+y*33); // on définie le 2e élément
                                            // [Déplacement sur une case space]
                                        if(eld->getTypeID()==state::TypeID::SPACE ){
                                            moteur->addCommand(new engine::MoveCommand(elm,eld,ListOfElements,ListOfUnits));
                                            moteur->apply();
                                            moteur->run();
                                            //render_mutex.unlock();
                                        }
                                        if(elm->getTypeID()==state::TypeID::FIGHTER && eld->getTypeID()==state::TypeID::WALL){
                                            moteur->addCommand(new engine::MoveCommand(elm,eld,ListOfElements,ListOfUnits));
                                            moteur->apply();
                                            moteur->run();
                                            //render_mutex.unlock();
                                        }
                                            // [Capture sur une case structure]
                                        if(eld->getTypeID()==state::TypeID::STRUCTURE){
                                            state::Structure* sd=static_cast<state::Structure*>(eld);
                                            state::MobileElement* sm=static_cast<state::MobileElement*>(elm);
                                            if(sd->getColor()==sm->getColor()){
                                                moteur->addCommand(new engine::MoveCommand(elm,eld,ListOfElements,ListOfUnits));
                                                moteur->apply();
                                                moteur->run();
                                                //render_mutex.unlock();
                                            }else{
                                                if(sm->getTypeID()==state::INFANTRY){
                                                    
                                                    int range = abs((eld->getY()-sm->getY())+(eld->getX()-sm->getX()));
                                                    if(range == 1){
                                                        state::Infantry* infm=static_cast<state::Infantry*>(sm);
                                                        state::Structure* toBeCaptured=static_cast<state::Structure*>(eld);
                                                        std::cout<<"Commande de capture enregistrée !"<<std::endl;
                                                        moteur->addCommand(new engine::CaptureCommand(infm,toBeCaptured));
                                                        moteur->apply();
                                                        moteur->run();
                                                        //render_mutex.unlock();
                                                    }
                                                    if( range > 1){
                                                        std::cout << "Il se peut que vous soyez trop éloigné : distance doit être égal à 1 case" << std::endl;
                                                    }
                                                }else{
                                                    std::cout<<"Il n'y a que les infantries qui peuvent capturer des structures"<<std::endl;
                                                }
                                            }
                                        }
                                        if(eld->getTypeID()==state::TypeID::ANTIAIR || eld->getTypeID()==state::TypeID::FIGHTER || eld->getTypeID()==state::TypeID::INFANTRY || eld->getTypeID()==state::TypeID::TANK){
                                            std::cout<<"Commande d'attaque enregistrée"<<std::endl;
                                            moteur->addCommand(new engine::AttackCommand(elm,eld,ListOfElements,ListOfUnits));
                                            moteur->apply();
                                            moteur->run();
                                            //render_mutex.unlock();
                                        }
                                        //render_mutex.lock();
                                        if (!map.load("res/Textures.png", sf::Vector2u(16, 16), ListOfUnits, 33, 16)) {
							std::cout << "an error occured" << std::endl;
						}
                                        //render_mutex.unlock();
                                        selected=0;
                                    }else{std::cout<<"Aucune unité sélectionné"<<std::endl;}
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
