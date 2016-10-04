/* 
   
 */

#ifndef _Element_hh_
#define _Element_hh_

class Element {

  protected:

    /*
     * Coordonnée en abscisse
     */

    int x;

    /*
     * Coordonnée en ordonnée
     */

    int y;
    Direction orientation;


  public:
    Element();
    virtual ~Element();
    int const getX();
    int const getY();
    Direction const getOrientation();
    void setX();
    void setY();
    void setOrientation();
    virtual bool const isStatic();
    virtual TypeID const getTypeID();
    virtual Element* const clone();
    virtual bool const equals(const Element& other) = 0;


};

#endif /* _Element_hh_ */

