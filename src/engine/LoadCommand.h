// Generated by dia2code
#ifndef ENGINE__LOADCOMMAND__H
#define ENGINE__LOADCOMMAND__H

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
    int getCategory () const;
    CommandTypeID getTypeID () const;
    const char*  getFileName () const;
    ~LoadCommand ();
  };

};

#endif
