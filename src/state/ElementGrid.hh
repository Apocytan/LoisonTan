/* 
   
 */

#ifndef _ElementGrid_hh_
#define _ElementGrid_hh_

class ElementGrid {

  protected:
    int width;
    int height;


  public:
    ElementGrid(State& s);
    ElementGrid* const clone();
    void copy(const ElementGrid* list);
    bool const equals(const ElementGrid& other);
    bool const hasCell(int i, int j);
    int const getWidth();
    int const getHeight(int i);
    Element* const getCell(int i, int j);
    bool const isSpace(int i, int j, Direction d = NONE);
    void setCell(int i, int j, Element* e);
    void load(const char* file_name);
    void const notifyObservers(int i = -1, int j = -1);


};

#endif /* _ElementGrid_hh_ */

