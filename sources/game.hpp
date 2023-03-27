#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"

namespace ariel{
    class Game {
    private:
        Player& one;
        Player& two;
    public:
        Game(Player& gamePlayer_1, Player& gamePlayer_2) : one(gamePlayer_1), two(gamePlayer_2) {}
        ~Game(){}
        void playAll(){}
        void printWiner(){}
        void printLog(){}
        void printStats(){}
        void printLastTurn(){}
        void playTurn(){}
    };
}

#endif /* GAME_HPP */
