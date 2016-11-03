// Generated by dia2code
#ifndef STATE__ELEMENTGRID__H
#define STATE__ELEMENTGRID__H


namespace state {
  class State;
  class Element;
  class ElementList;
}

#include "Direction.h"
#include "ElementList.h"

namespace state {

  /// class ElementGrid - 
  class ElementGrid : public state::ElementList {
    // Attributes
  protected:
    int width;
    int height;
    // Operations
  public:
    ElementGrid (State& s);
    bool hasCell (int i, int j) const;
    int getWidth () const;
    int getHeight () const;
    Element* getCell (int i, int j) const;
    bool isSpace (int i, int j, Direction d = NONE) const;
    void setCell (int i, int j, Element* e);
    void load (const char* file_name);
  };

};

#endif
