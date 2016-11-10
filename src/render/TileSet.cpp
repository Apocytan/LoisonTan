#include "TileSet.h"
#include <SFML/Graphics.hpp>
#define tileSize sf::Vector2u(16,16)

namespace render{
    int TileSet::getCellWidth() const{
        return 33;
    }
    int TileSet::getCellHeight() const{
        return 16;
    }
    const std::string& TileSet::getImageFile() const{
        return "../../res/Textures.png";
    }
    const Tile* TileSet::getElementTile(const state::Element* e) const{
        const Tile* tile=new Tile();
        
        const std::string& tileset=getImageFile();
        m_tileset.loadFromFile(tileset);
        int TileNumber;
        if(e->getTypeID()==0){//wall
            state::Wall* w = static_cast<state::Wall*>(e);
            if(w->getWallTypeID()==1){
                TileNumber=24;
            }
            if(w->getWallTypeID()==2){
                TileNumber=27;
            }
            if(w->getWallTypeID()==3){
                TileNumber=28;
            }
            if(w->getWallTypeID()==4){
                TileNumber=29;
            }
            if(w->getWallTypeID()==5){
                TileNumber=32;
            }
            if(w->getWallTypeID()==6){
                TileNumber=33;
            }
            if(w->getWallTypeID()==7){
                TileNumber=34;
            }
            if(w->getWallTypeID()==8){
                TileNumber=30;
            }
        }
        if(e->getTypeID()==1){//Space
            state::Space* s = static_cast<state::Space*>(e);
            if(s->getSpaceTypeID()==1){
                TileNumber=25;
            }
            if(s->getSpaceTypeID()==2){
                TileNumber=26;
            }
            if(s->getSpaceTypeID()==3){
                TileNumber=35;
            }
            if(s->getSpaceTypeID()==4){
                TileNumber=36;
            }
            if(s->getSpaceTypeID()==5){
                TileNumber=37;
            }
            if(s->getSpaceTypeID()==6){
                TileNumber=38;
            }
            if(s->getSpaceTypeID()==7){
                TileNumber=39;
            }
            if(s->getSpaceTypeID()==8){
                TileNumber=31;
            }
        }
        if(e->getTypeID()==2){//fighter
            state::MobileElement* me = static_cast<state::MobileElement*>(e);
            if(me->getColor()==1){ //1: bleu
                TileNumber=5;
            }
            if(me->getColor()==2){ //2:rouge
                TileNumber=0;
            }
        }
        if(e->getTypeID()==3){//infantry
            state::MobileElement* me = static_cast<state::MobileElement*>(e);
            if(me->getColor()==1){ //1: bleu
                TileNumber=6;
            }
            if(me->getColor()==2){ //2:rouge
                TileNumber=1;
            }
        }
        if(e->getTypeID()==4){//tank
            state::MobileElement* me = static_cast<state::MobileElement*>(e);
            if(me->getColor()==1){ //1: bleu
                TileNumber=7;
            }
            if(me->getColor()==2){ //2:rouge
                TileNumber=2;
            }
        }
        if(e->getTypeID()==5){//Antiair
            state::MobileElement* me = static_cast<state::MobileElement*>(e);
            if(me->getColor()==1){ //1: bleu
                TileNumber=8;
            }
            if(me->getColor()==2){ //2:rouge
                TileNumber=3;
            }
        }
        if(e->getTypeID()==6){//Structures
            state::Structure* s = static_cast<state::Structure*>(e);
            if(s->getSpaceTypeID()==1){//mine
                if(s->getColor()==0){//0:neutre
                    TileNumber=23;
                }
                if(s->getColor()==1){//1:bleu
                    TileNumber=18;
                }
                if(s->getColor()==2){//2:rouge
                    TileNumber=13;
                }
            }
            if(s->getSpaceTypeID()==2){//building
                if(s->getColor()==0){//0:neutre
                    TileNumber=22;
                }
                if(s->getColor()==1){//1:bleu
                    TileNumber=17;
                }
                if(s->getColor()==2){//2:rouge
                    TileNumber=12;
                }
            }
            if(s->getSpaceTypeID()==3){//headquarter
                if(s->getColor()==1){//1:bleu
                    TileNumber=19;
                }
                if(s->getColor()==2){//2:rouge
                    TileNumber=14;
                }
            }
            if(s->getSpaceTypeID()==4){//factory
                if(s->getColor()==0){//0:neutre
                    TileNumber=20;
                }
                if(s->getColor()==1){//1:bleu
                    TileNumber=15;
                }
                if(s->getColor()==2){//2:rouge
                    TileNumber=10;
                }
            }
            if(s->getSpaceTypeID()==5){//airport
                if(s->getColor()==0){//0:neutre
                    TileNumber=21;
                }
                if(s->getColor()==1){//1:bleu
                    TileNumber=16;
                }
                if(s->getColor()==2){//2:rouge
                    TileNumber=11;
                }
            }
        }
        StaticTile* s = static_cast<StaticTile*>(tile);
        // on en déduit sa position dans la texture du tileset
        int tu = TileNumber % (m_tileset.getSize().x / tileSize.x);
        int tv = TileNumber / (m_tileset.getSize().x / tileSize.x);
        s->setX(tu);
        s->setY(tv);
        return tile;
        
    }
}
