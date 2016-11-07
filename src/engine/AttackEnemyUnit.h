// Generated by dia2code
#ifndef ENGINE__ATTACKENEMYUNIT__H
#define ENGINE__ATTACKENEMYUNIT__H


namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class AttackEnemyUnit - 
  class AttackEnemyUnit : public engine::Action {
    // Attributes
  protected:
    int attacker;
    int defender;
    // Operations
  public:
    AttackEnemyUnit (int attacker, int defender);
    ~AttackEnemyUnit ();
  };

};

#endif
