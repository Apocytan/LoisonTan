/*#include "Client.h"
#include <SFML/Network.hpp>
#include <json/json.h>
namespace client{
    Client::Client (server::Server* serv){
        this->server=serv;
    }
    Client::~Client (){
        
    }
    void Client::serverChanged (server::ServerEvent& sc){
        sf::Http http("172.17.0.1");
        //requête post pour envoyer la notification sc au stateObserver et au serverObserver
        sf::Http::Request request;
        //paramétrage de la requête
        request.setMethod(sf::Http::Request::Post);
        request.setUri("172.17.0.1");
        //request.setField();
        //construction du Json
        Json::Value out;
        //fin de construction du Json
        //request.setBody();
        //fin de paramétrage
        sf::Http::Response response=http.sendRequest(request);
    }
}*/