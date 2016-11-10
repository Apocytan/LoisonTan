#include "Engine.h"
#include <SFML/Window/Mouse.hpp>
#include <iostream>
namespace engine{
    
    Engine::~Engine (){
        
    }
 
    Engine::Engine (){
        
    }
    EngineMode  Engine::getMode () const{
        return PLAY; // test
    }

    void  Engine::addCommand (Command* cmd){
        
    }
    void  Engine::takeCommands (CommandSet& commands){
        // prend les commandes du clavier
        
        
    }

    void  Engine::loadLevel (const char* file_name) const{
        
    }
    void  Engine::setMode (EngineMode mode){
        
    }
    // étrange
    int Engine::TakeEventX(sf::Event event) {
        int x=0;
        x = event.mouseButton.x;
        x = x / 16;
        return x;
        
    }
    int Engine::TakeEventY(sf::Event event) {
        int y=0;
        y = event.mouseButton.y;
        y = y / 16;
        return y;
    }
    std::string Engine::TakeEventTile(std::vector<std::string> levelwUnit, int x, int y) {
        std::string tileLetter="rF";
        tileLetter = levelwUnit[x+y*33];
        return tileLetter;
    }
    /*std::tuple <int,int,std::string> getEvent (std::vector<std::string> levelwUnit, sf::Event event){
        int x=0;
        int y=0;
        std::string tileLetter="rF";
           if(event.type==sf::Event::MouseButtonPressed){    
                                if (event.mouseButton.button == sf::Mouse::Left){
                                    x = event.mouseButton.x;
                                    y = event.mouseButton.y;
                                    x = x / 16;
                                    y = y / 16;
                                    tileLetter = levelwUnit[x+y*33];
                                    
                                }
                                }
         return std::make_tuple(x,y,tileLetter); // renvoie un tuple #dédicace D.B
        }*/
    

}