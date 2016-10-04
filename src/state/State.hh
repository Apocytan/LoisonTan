/* 
   
 */

#ifndef _State_hh_
#define _State_hh_

class State {

  protected:
    ElementList chars;
    ElementGrid grid;
    int iron;
    int units;


  public:
    State();
    ~State();
    State* const clone();
    bool const equals(const State& other);
    int const getIron();
    int const getUnit();
    const ElementGrid& const getGrid();
    ElementGrid& getGrid();
    const ElementList& const getChars();
    ElementList& getChars();
    const MobileElement* const getChar(int idx);
    MobileElement* getChar(int idx);
    void setElementFactory(ElementFactory* f);
    void setIron(int res);
    void setUnits(int count);
    void setGrid(const ElementGrid& grid);
    void setChars(const ElementList& list);
    void const notifyObservers(StateEventID id);
    void const notifyObservers(const StateEvent& e);


};

#endif /* _State_hh_ */

