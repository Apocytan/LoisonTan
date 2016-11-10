#include "AttackEnemyUnit.h"


namespace engine {
    AttackEnemyUnit::AttackEnemyUnit (state::MobileElement* attacker, state::MobileElement* defender){
        this->attacker=attacker;
        this->defender=defender;
    }
    AttackEnemyUnit::~AttackEnemyUnit (){
        delete &attacker;
        delete &defender;
    }

}