/**
 * Test file
 */
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

TEST_CASE("Test Number 1: count of card") {
  Player p1("Alice");
  Player p2("Bob");
  Game game(p1,p2);

  CHECK_EQ(p1.stacksize(), 26);
  CHECK_EQ(p1.stacksize(), 26);
};

TEST_CASE("Test Number 2:  Winner can't be before starting a game") {
  Player p1("Alice");
  Player p2("Bob");
  Game game(p1,p2);

  CHECK_THROWS(game.printWiner());
}

TEST_CASE("Test Number 3: Printing the winner") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
};

TEST_CASE("Test Number 4: Game log") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printLog());
};

TEST_CASE("Test Number 5: Turns after game end") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    CHECK_NOTHROW(game.playAll());
    CHECK_THROWS(game.playTurn());
};

TEST_CASE("Test Number 6: Stack size plater no 1") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    game.playAll();
    CHECK((p1.stacksize() == 0 || p1.stacksize() == 52));
};

TEST_CASE("Test Number 7: Stack size plater no 2") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    game.playAll();
    CHECK((p2.stacksize() == 0 || p2.stacksize() == 52));
};

TEST_CASE("Test Number 8: Game play all") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    game.playAll();
    CHECK((p1.stacksize() == 52 || p2.stacksize() == 52));
};

TEST_CASE("Test Number 9: After two turns for player no 1") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    game.playTurn();
    game.playTurn();

    CHECK((p1.stacksize() == 24 || p1.stacksize() == 26 || p1.stacksize() == 28 || p1.stacksize() == 29 || p1.stacksize() == 23));
    // p1 can: win+win, win+lost = lost+win, lost+lost, draw+lost, draw+win, draw+darw, win+darw
    //            28             26              24         23        29         23       26
};

TEST_CASE("Test Number 10: After two turns for player no 2") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    game.playTurn();
    game.playTurn();

    CHECK((p2.stacksize() == 24 || p2.stacksize() == 26 || p2.stacksize() == 28 || p2.stacksize() == 29 || p2.stacksize() == 23));
    // p2 can: win+win, win+lost = lost+win, lost+lost, draw+lost, draw+win, draw+darw, win+darw
    //            28             26              24         23        29         23       26
};

TEST_CASE("Test Number 11: Game play turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    for(int i = 0; i < 6; i++){
      game.playTurn();
    }
    CHECK_NOTHROW(game.playTurn());
};

TEST_CASE("Test Number 12: Player no 2 cardesTaken") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();

    CHECK((p2.cardesTaken() == 0 || p2.cardesTaken() == 1));
};

TEST_CASE("Test Number 13: Player no 1 cardesTaken") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();

    CHECK((p1.cardesTaken() == 0 || p1.cardesTaken() == 1));
};

TEST_CASE("Test Number 14: Game play turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    for(int i = 0; i < 6; i++){
      CHECK_NOTHROW(game.playTurn());
    }
};

TEST_CASE("Test Number 15: Player no 1 cardesTaken after two turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    game.playTurn();

    CHECK((p1.cardesTaken() == 0 || p1.cardesTaken() == 1 || p1.cardesTaken() == 2));
    // p1 can: win+win, win+lost = lost+win, lost+lost, draw+lost=draw+win, draw+darw, win+darw
    //            2              1                0              1              0         1           
};

TEST_CASE("Test Number 16: Player no 2 cardesTaken after two turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    game.playTurn();

    CHECK((p2.cardesTaken() == 0 || p2.cardesTaken() == 1 || p2.cardesTaken() == 2));
    // p1 can: win+win, win+lost = lost+win, lost+lost, draw+lost=draw+win, draw+darw, win+darw
    //            2              1                0              1              0         1           
};

TEST_CASE("Test Number 17: printStats() can't be before starting a game") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    CHECK_THROWS(game.printStats());
};

TEST_CASE("Test Number 18: printStats() after 6 turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    for(int i = 0; i < 6; i++){
      CHECK_NOTHROW(game.printStats());
    }
};

TEST_CASE("Test Number 19: printLastTurn can't be before starting a game") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    CHECK_THROWS(game.printLastTurn());
};

TEST_CASE("Test Number 20: Winner can't be after 6 turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    for(int i = 0; i < 6; i++){
      game.playTurn();
    }

    CHECK_THROWS(game.printWiner());
};

TEST_CASE("Test Number 21: Game log for 6 game") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    for(int i = 0; i < 6; i++){
      CHECK_NOTHROW(game.printLog());
    }
};