#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

//#include "player.hpp"
//#include "card.hpp"
//using namespace ariel;

namespace ariel{
class Player
{
private:
    string name;
    int amount_cards;
    int amount_winning;
    //cards

    

public:
    Player(string const &name);
    Player(){}
    ~Player();
    int stacksize(){return 1;}
    int cardesTaken(){return 1;}
    int getNumCard();
    int addWin(card);// and to the cardsTaken
    int gatWinings();
    string getName();
    string cardToString();
};

Player::Player(string const &name)
{
}

Player::~Player()
{
}
}
