/* 
   
 */

#ifndef _Tank_hh_
#define _Tank_hh_

class Tank {


  public:
    Tank();
    bool const isAir();
    TypeID const getTypeID();
    Element* const clone();
    bool const equals(const Element& other);


};

#endif /* _Tank_hh_ */

