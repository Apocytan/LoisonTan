// Generated by dia2code
#ifndef ENGINE__LOADCOMMAND__H
#define ENGINE__LOADCOMMAND__H

#include <iostream>
#include <string>

namespace engine {
  class Command;
}

#include "CommandTypeID.h"
#include "Command.h"

namespace engine {

  /// class LoadCommand - 
  class LoadCommand : public engine::Command {
    // Attributes
  protected:
    std::string file_name;
    // Operations
  public:
    LoadCommand (const char* f);
    ~LoadCommand ();
    int getCategory () const;
    CommandTypeID getCommandTypeID () const;
    const char*  getFileName () const;
  };

};

#endif
