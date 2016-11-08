/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Engine.h"

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
        
    }

    void  Engine::loadLevel (const char* file_name) const{
        
    }
    void  Engine::setMode (EngineMode mode){
        
    }
    // étrange

}