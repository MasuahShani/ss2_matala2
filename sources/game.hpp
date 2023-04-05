#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "player.hpp"
//#include "game.hpp"
//#include "card.hpp"
using namespace ariel;


namespace ariel{
class Game
{
private:
    Player p1;
    Player p2;
    string situations;
    string lastTurn;
    int winer;
    int drowns;
    

public:
    Game(Player& p1, Player& p2);
    ~Game();
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

};

Game::Game(Player &p1, Player &p2)
{
    // this->p1=p1;
    // this->p2=p2;
}

Game::~Game()
{
}
}



