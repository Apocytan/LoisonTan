/* 
   
 */

#ifndef _Observable_hh_
#define _Observable_hh_

class Observable {

  protected:
    mutable std::vector<StateObserver*> observers;


  public:
    virtual ~Observable() = 0;
    void const registerObserver(StateObserver* o);
    void const unregisterObserver(StateObserver* o);
    void const notifyObservers(const StateEvent& e);


};

#endif /* _Observable_hh_ */

