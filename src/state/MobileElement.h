// Generated by dia2code
#ifndef STATE__MOBILEELEMENT__H
#define STATE__MOBILEELEMENT__H


namespace state {
  class Element;
}
#include <typeinfo>
#include "Direction.h"
#include "Element.h"

namespace state {

  /// class MobileElement - 
  class MobileElement : public state::Element {
    // Associations
    state::Direction direction;
    // Attributes
  protected:
    int speed;
    int position;
    int color;
    bool rank;
    int hitpoints;
    int damage;
    // Operations
  public:
    MobileElement ();
    Direction getDirection() const;
    int getSpeed() const;
    int getPosition() const;
    void setDirection (Direction d);
    void setSpeed (int sp);
    void setPosition (int pos);
    /// Mobile ou Statique ?
    bool const isStatic ();
    virtual bool const isAir ();
    virtual bool const equals (const Element& other) = 0;
    void setColor (int c);
    int getColor() const;
    void setRank (bool rank);
    bool getRank () const;
    void setHp (int hp);
    int  getHp() const;
    void setDamage (int d);
    int  getDamage() const;
  };

};

#endif
