//#include "CommandDB.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <exception>
#include <istream>
#include <json/json.h>
/*
class JSONValue;


namespace server{
    
    /*CommandDB::CommandDB(engine::CommandSet* srvcmd){
        this->srvcmd=srvcmd;
        this->commandIndex=commandIndex;
    }
    void CommandDB::addCommand (){
        //servcmd->commands.push();
    }
    
    ServerEvent CommandDB::getCommand (Json::Value& out , int id ){
        // Renvoi de la commande au joueur le souhaitant afin de l'informer du type de commande que l'autre joueur a effectué
        out["CommandTypeID"]= servcmd->commands.at(id)->getCommandTypeID();
                
    }
    
       /* const User* user = userDB.getUser(id);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    out["name"] = user->name;
    out["age"] = user->age;
    return HttpStatus::OK;
}*/