#include "StaticTile.h"
#include <SFML/Graphics.hpp>
namespace render{
    StaticTile (int x = 0, int y = 0, int w = 16, int h = 16){
        
    }
    bool isAnimated () const{
        return false;
    }
    int getX () const{
        return x;
    }
    int getY () const{
        return this->y;
    }
    int getWidth () const{
        return this->width;
    }
    int getHeight () const{
        return this->height;
    }
    int setX (int x) const{
        this->x=x;
    }
    int setY (int y) const{
        this->y=y;
    }
    int setWidth (int w) const{
        this->width=w;
    }
    int setHeight (int h) const{
        this->height=h;
    }
    
}