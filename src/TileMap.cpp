#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "state/TypeID.h"
#include "state/ElementList.h"
#include "state/Wall.h"
#include "../src/state.h"
#include "../src/state/TypeID.h"
#include "../src/state/SpaceTypeID.h"
#include "../src/state/StructureTypeID.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, state::ElementList *elemList/*const std::vector<std::string> tiles*/, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        state::Element* e;
        int TileNumber;
        /*std::unordered_map<std::string,int> list={//W:woods, machinW: machinWater, brR: bottomRightRoad
                {"rfighter",0},{"rinfantry",1},{"rtank",2},{"rantiair",3},
                {"bfighter",5},{"binfantry",6},{"btank",7},{"bantiair",8},
                {"rF",10},{"rA",11},{"rB",12},{"rM",13},{"rHQ",14},
                {"bF",15},{"bA",16},{"bB",17},{"bM",18},{"bHQ",19},
                {"nF",20},{"nA",21},{"nB",22},{"nM",23},{"S",24},
                {"vR",25},{"hR",26},{"hW",27},{"tW",28},{"lW",29},
                {"W",30},{"G",31},{"vW",32},{"bW",33},{"rW",34},
                {"brR",35},{"blR",36},{"tlR",37},{"trR",38},{"R",39}};*/
        
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                e=elemList->elements.at(i+j*width);
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
                    if(s->getStructureTypeID()==1){//mine
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
                    if(s->getStructureTypeID()==2){//building
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
                    if(s->getStructureTypeID()==3){//headquarter
                        if(s->getColor()==1){//1:bleu
                            TileNumber=19;
                        }
                        if(s->getColor()==2){//2:rouge
                            TileNumber=14;
                        }
                    }
                    if(s->getStructureTypeID()==4){//factory
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
                    if(s->getStructureTypeID()==5){//airport
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
                // on récupère la lettre de tuile courant
                /*std::string tileLetter = tiles[i + j * width];
                
                // on assigne la lettre à un numéro qui correspond à la position de la tuile dans la texture
                int tileNumber=list[tileLetter];*/
                
                // on en déduit sa position dans la texture du tileset
                int tu = TileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = TileNumber / (m_tileset.getSize().x / tileSize.x);
                
                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }
private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};