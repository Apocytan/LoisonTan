#include "ActionList.h"

namespace engine{
    ActionList::ActionList(state::State& s, bool notify): s(s), notify(notify){
        
    }
    ActionList::~ActionList(){
        delete &s;
        delete &notify;
    }
    int ActionList::size () const{
        return actions.size();
    }
    Action* ActionList::get (int i) const{
        return actions.at(i);
    }

    void ActionList::add (Action* action){
        actions.push_back(action);
    }
}