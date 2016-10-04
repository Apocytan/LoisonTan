/* 
   
 */

#ifndef _AntiAir_hh_
#define _AntiAir_hh_

class AntiAir {


  public:
    AntiAir();
    bool const isAir();
    TypeID const getTypeID();
    Element* const clone();
    bool const equals(const Element& other);


};

#endif /* _AntiAir_hh_ */

