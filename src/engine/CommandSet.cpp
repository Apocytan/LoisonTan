#include "CommandSet.h"
#include <iostream>
#include <vector>

namespace engine{
    
    CommandSet::CommandSet (std::vector<Command*> commands){
        this->commands=commands;
    }
    CommandSet::~CommandSet(){
        
    }
    int CommandSet::size() const {
        return commands.size();
    }
    Command* CommandSet::getCommand (int i){
        return commands.at(i);
    }
    void CommandSet::setCommand (Command* command){
        commands.push_back(command);
    }
    
}