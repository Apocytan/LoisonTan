#include "Scene.h"
#include <SFML/Graphics.hpp>
namespace render{
    Scene::Scene(){
        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        this->m_vertices.setPrimitiveType(sf::Quads);
        this->m_vertices.resize(width * height * 4);
        
    }
    
}