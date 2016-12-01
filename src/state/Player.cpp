#include "Player.h"

namespace state{
    Player::Player (){
        this->iron=iron;
        this->units=units;
        this->color=color;
    }
    void Player::setIron (int iron){
        this->iron=iron;
    }
    void Player::setUnits (int nbunits){
        units=nbunits;
    }
    void Player::setColor (int playercolor){
        color=playercolor;
    }
    int Player::getIron (){
        return iron;
    }
    int Player::getUnits (){
        return units;
    }
    int Player::getColor (){
        return color;
    }
}