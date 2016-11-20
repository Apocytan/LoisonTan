/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "BuildCommand.h"
#include <iostream>
namespace engine {
    Command::~Command(){
        
    }
    int BuildCommand::getBuildCommand () const{
        return 1;
    }
    BuildCommand::~BuildCommand (){
        
    }
    void BuildCommand::execute () const{
        std::cout << "J'exécute build command" <<std::endl;
    }
    void Command::execute() const{
        
    }
}