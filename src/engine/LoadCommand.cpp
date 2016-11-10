#include "LoadCommand.h"
#include <iostream>
#include <fstream>

namespace engine {
    //constructeur pour récupérer un fichier dont le nom est "f" 
    LoadCommand::LoadCommand (const char* f){
    }
    LoadCommand::~LoadCommand(){
        
    }
    int LoadCommand::getCategory () const{
        return 1; // provisoire
    }
    CommandTypeID LoadCommand::getTypeID() const{
        return LOAD;
    }
    const char*  LoadCommand::getFileName () const{
        
        char* a = a;
        return a; // provisoire
    }
    
    // étrange erreur
    Command::~Command(){
        
    }
    int Command::getCategory() const{
        return 0;
    }
    CommandTypeID Command::getTypeID() const{
        return LOAD;
    }
}