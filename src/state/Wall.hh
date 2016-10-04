/* 
   
 */

#ifndef _Wall_hh_
#define _Wall_hh_

class Wall {


  public:
    Wall(WallTypeID wid);
    bool const isSpace();
    TypeID const getTypeID();
    const getWallTypeID();
    void setWallTypeID(WallTypeID wid);
    Element* const clone();
    bool const equals(const Element& other);


};

#endif /* _Wall_hh_ */

