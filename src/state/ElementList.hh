/* 
   
 */

#ifndef _ElementList_hh_
#define _ElementList_hh_

class ElementList {

  protected:
    State& s;
    ElementFactory* factory;

  public:
    std::vector<Element*> elements;


  public:
    ElementList(State& s);
    ~ElementList();
    ElementList* const clone();
    void copy(const ElementList* list);
    bool const equals(const ElementList& other);
    const State& const getState();
    int const size();
    Element* const get(int i);
    void clear();
    void setElementFactory(ElementFactory* f);
    void set(int i, Element* e);
    void const notifyObservers(int i = -1);


};

#endif /* _ElementList_hh_ */

