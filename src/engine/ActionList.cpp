#include "ActionList.h"

namespace engine{
    ActionList::ActionList(std::vector<Action*> actions){
        this->actions=actions;
    }
    
    ActionList::~ActionList(){
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