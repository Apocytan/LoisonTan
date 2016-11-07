/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AttackEnemyUnit.h"


namespace engine {
    AttackEnemyUnit::AttackEnemyUnit (int attacker, int defender){
        this->attacker=attacker;
        this->defender=defender;
    }
    AttackEnemyUnit::~AttackEnemyUnit (){
        
    }
    void AttackEnemyUnit::apply (state::State& s, bool notify){

    }
    void AttackEnemyUnit::undo (state::State& s, bool notify){

    }
}