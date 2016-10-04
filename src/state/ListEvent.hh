/* 
   
 */

#ifndef _ListEvent_hh_
#define _ListEvent_hh_

class ListEvent {

  public:
    const ElementList& list;
    int idx;


  public:
    ListEvent(const ElementList& list, int idx);
    StateEvent* const clone();


};

#endif /* _ListEvent_hh_ */

