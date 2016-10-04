/* 
   
 */

#ifndef _StateObserver_hh_
#define _StateObserver_hh_

class StateObserver {


  public:
    virtual void stateChanged(const StateEvent& e) = 0;


};

#endif /* _StateObserver_hh_ */

