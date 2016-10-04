/* 
   
 */

#ifndef _StateEvent_hh_
#define _StateEvent_hh_

class StateEvent {

  public:
    const State& state;


  public:
    StateEvent(const State& s, StateEventID id);
    virtual ~StateEvent() = 0;
    virtual StateEvent* const clone() = 0;
    bool const operator==(StateEventID id);
    bool const operator!=(StateEventID id);


};

#endif /* _StateEvent_hh_ */

