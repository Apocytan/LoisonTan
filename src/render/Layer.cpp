#include "Layer.h"
#include <SFML/Graphics.hpp>
namespace render{
    Layer (){
        
    }
    virtual ~Layer (){
        
    }
    const TileSet* getTileSet () const{
        return this->tileset;
    }
    void setTileSet (const TileSet* tileset){
        this->tileset=tileset;
    }

    void printText (int x, int y, shared_ptr<char> txt, int w, int h){
        
    }
    void setSurface(Surface* surface){
        this->surface=surface;
    }
}