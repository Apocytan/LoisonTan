#include "Surface.h"
#include <SFML/Graphics.hpp>
#define tileSize sf::Vector2u(16,16)
namespace render{
    void clear (){
        
    }
    void loadTexture (const std::string& image_file){
        

    }
    void setSpriteLocation (int i, int x, int y){
            sf::VertexArray m_vertices;
    
        // on récupère un pointeur vers le quad à définir dans le tableau de vertex
        sf::Vertex* quad = &m_vertices[i * 4];
        
        // on définit ses quatre coins
        quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
        quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
        quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
        quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);
    }
    void setSpriteTexture (int i, const StaticTile* tex){
        sf::VertexArray m_vertices;
    
        int tu=tex-();
        int tv=tex->getY();
        // on récupère un pointeur vers le quad à définir dans le tableau de vertex
        sf::Vertex* quad = &m_vertices[i * 4];
        // on définit ses quatre coordonnées de texture
        quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
        quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
        quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
        quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
    }
}