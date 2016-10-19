#include <iostream>
#include "TileMap.cpp"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    //sf::Texture texture;
    /*sf::RenderWindow window(sf::VideoMode(200,200),"SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }*/
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(600, 256), "Tilemap");

    // on définit le niveau à l'aide de numéro de tuiles
    const std::string level[] =
    {
	"rF","G","G","G","rF","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G",
	"G","tlR","hR","hR","trR","G","G","G","G","G","G","G","G","G","G","S","G","tlR","hR","hR","hR","hR","hR","hR","trR","G","G","S","G","G","G","G","G",
	"G","vR","rHQ","rM","vR","G","G","G","G","tlR","hR","hR","hR","hR","hR","hR","hR","vR","nF","W","W","G","G","G","vR","S","S","S","S","S","G","G","G",
	"rA","vR","nB","nB","rF","G","G","G","G","vR","nM","S","S","S","W","S","W","vR","W","W","W","W","G","G","vR","S","S","S","S","S","S","G","G",
	"G","blR","hR","hR","hR","hR","hR","hR","hR","brR","W","S","W","W","W","W","nB","vR","G","G","tlR","hR","hR","hR","hR","trR","S","S","S","S","S","S","G",
	"G","G","G","G","G","G","W","vR","W","W","W","W","W","tlR","hR","hR","hR","hR","hR","hR","brR","nB","W","W","W","vR","S","G","S","S","S","G","G",
	"G","G","G","G","G","G","G","vR","W","W","W","W","W","vR","nM","W","G","G","G","vR","S","W","W","W","W","vR","S","G","S","nM","S","G","G",
	"G","G","G","G","G","G","W","vR","W","W","W","W","nB","vR","W","W","G","G","S","vR","S","W","W","W","W","vR","nA","G","G","G","G","G","G",
	"G","G","G","G","G","G","nA","vR","W","W","W","W","S","vR","S","G","G","W","W","vR","nB","W","W","W","W","vR","W","G","G","G","G","G","G",
	"G","G","S","nM","S","G","S","vR","W","W","W","W","S","vR","G","G","G","W","nM","vR","W","W","W","W","W","vR","G","G","G","G","G","G","G",
	"G","G","S","S","S","G","S","vR","W","W","W","nB","tlR","hR","hR","hR","hR","hR","hR","brR","W","W","W","W","W","vR","W","G","G","G","G","G","G",
	"G","S","S","S","S","S","S","blR","hR","hR","hR","hR","brR","G","G","vR","nB","W","W","W","W","S","W","tlR","hR","hR","hR","hR","hR","hR","hR","trR","G",
	"G","G","S","S","S","S","S","S","vR","G","G","W","W","W","W","vR","W","S","W","S","S","S","nM","vR","G","G","G","G","bF","nB","nB","vR","bA",
	"G","G","G","S","S","S","S","S","vR","G","G","G","W","W","nF","vR","hR","hR","hR","hR","hR","hR","hR","brR","G","G","G","G","vR","bM","bHQ","vR","G",
	"G","G","G","G","G","S","G","G","blR","hR","hR","hR","hR","hR","hR","brR","G","S","G","G","G","G","G","G","G","G","G","G","blR","hR","hR","brR","G",
	"G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","G","bF","G","G","G","bF",
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("res/Textures.png", sf::Vector2u(16, 16), level, 33, 16))
        std::cout<<"an error occured"<<std::endl;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }

}


// Fin test SFML

#include "state.hpp"

using namespace std;
using namespace state;

/*int main(int argc,char* argv[]) 
{
    Exemple exemple;
    exemple.setX(3);

    cout << "It works !" << endl;

    return 0;
}
*/

int main(){
    testSFML();
    return 0;
}