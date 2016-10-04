/* 
   
 */

#ifndef _Fighter_hh_
#define _Fighter_hh_

class Fighter {


  public:
    Fighter();
    bool const isAir();
    TypeID const getTypeID();
    Element* const clone();
    bool const equals(const Element& other);


};

#endif /* _Fighter_hh_ */

