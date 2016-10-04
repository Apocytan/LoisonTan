/* 
   
 */

#ifndef _MobileElement_hh_
#define _MobileElement_hh_

class MobileElement {

  protected:
    int speed;
    int position;
    int color;
    bool rank;
    int hitpoints;
    int damage;


  public:
    MobileElement();
    Direction const getDirection();
    int const getSpeed();
    int const getPosition();
    void setDirection(Direction d);
    void setSpeed(int sp);
    void setPosition(int pos);

    /*
     * Mobile ou Statique ?
     */

    bool const isStatic();
    virtual bool const isAir();
    virtual bool const equals(const Element& other) = 0;
    void setColor(int c);
    int const getColor();
    void setRank(bool rank);
    bool const getRank();
    void setHp(int hp);
    int const getHp();
    void setDamage(int d);
    int const getDamage();


};

#endif /* _MobileElement_hh_ */

