/* 
   
 */

#ifndef _Space_hh_
#define _Space_hh_

class Space {


  public:
    Space(SpaceTypeID sid);
    bool const isSpace();
    TypeID const getTypeID();
    SpaceTypeID const getSpaceTypeID();
    void setSpaceTypeID(SpaceTypeID sid);
    Element* const clone();
    bool const equals(const Element& other);


};

#endif /* _Space_hh_ */

