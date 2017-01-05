#include "Observable.h"

namespace server{
    Observable::~Observable(){
    }
    void Observable::addObserver (ServerObserver* obs) const{
        //observers.push_back(obs);
    }
    void Observable::deleteObserver (ServerObserver* obs) const{
        //observers.erase(obs);
    }
}