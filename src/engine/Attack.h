// Generated by dia2code
#ifndef ENGINE__ATTACK__H
#define ENGINE__ATTACK__H

#include <iostream>

namespace state {
  class Element;
  class ElementList;
};
namespace engine {
  class Action;
};
namespace state {
  class MobileElement;
}

#include "Action.h"
#include "state/MobileElement.h"
#include "state/Element.h"
#include "state/ElementList.h"

namespace engine {

  /// class Attack - 
  class Attack : public engine::Action {
    // Attributes
  protected:
    state::Element* attacker;
    state::Element* defender;
    state::ElementList* StaticMap;
    state::ElementList* MapUnits;
    // Operations
  public:
    Attack (state::Element* attacker, state::Element* defender, state::ElementList* StaticMap, state::ElementList* MapUnits);
    ~Attack ();
    void execute () const;
  };

};

#endif
