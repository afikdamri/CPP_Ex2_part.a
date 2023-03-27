#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>

#include "card.hpp"

namespace ariel {
    class Player {
    private:
        std::string playerName;
    public:
        Player(const std::string name);
        ~Player();
        static int stacksize(){return -1;};
        static int cardesTaken(){return -1;};
    };

    Player::Player(const std::string name){
       this->playerName = name;
    }

    Player::~Player(){}
}
#endif