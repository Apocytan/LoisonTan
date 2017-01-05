/*#include "StateDB.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <exception>
#include <istream>



namespace server{
    
    void StateDB::addElement (){
        
    }
    ServerEvent StateDB::getElement (Json::Value& out , int id ){
        // Renvoi l'état courant au joueur le souhaitant afin de l'informer du type de commande que l'autre joueur a effectué
        //out["CommandTypeID"]= states->elements.at(id)->getCommandTypeID();
                
    }
    
       /* const User* user = userDB.getUser(id);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    out["name"] = user->name;
    out["age"] = user->age;
    return HttpStatus::OK;
}*/