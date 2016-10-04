/* 
   
 */

#ifndef _Infantry_hh_
#define _Infantry_hh_

class Infantry {


  public:
    Infantry();
    bool const isAir();
    TypeID const getTypeID();
    Element* const clone();
    bool const equals(const Element& other);


};

#endif /* _Infantry_hh_ */

