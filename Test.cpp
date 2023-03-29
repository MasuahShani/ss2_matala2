#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "sources/player.hpp"
#include "sources/game.hpp"
using namespace ariel;

///קיבלתי עזרה מהמתרגלת חרות ועל הניימספייס שבקושי למדנו- מהווצאפ


//1
// TEST_CASE("The players are null")
// {   
//     CHECK_NOTHROW(Game game(NULL,NULL));
// }
TEST_CASE("play turn after the game finish")
{
     Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();

    CHECK_NOTHROW(game.playTurn());


}
//2
TEST_CASE("Same names")
{
    Player p1("Alice");
    Player p2("Alice");

    CHECK_NOTHROW(Game game(p1,p2));  
}
//3
TEST_CASE("Same player")
{
    Player p1("Alice");
    CHECK_NOTHROW(Game game(p1,p1));

}
//4
TEST_CASE("Player in 2 games")
{
    Player p1("Alice");
    Player p2("Bob");
    Player p3 ("Mosh");
    Game game1(p1,p2);
    CHECK_NOTHROW(Game game2(p1,p3));
    CHECK_NOTHROW(Game game2(p3,p1));


}
//5
// TEST_CASE("One of the players are null")
// {
//     Player p1("Alice");
//     CHECK_NOTHROW(Game game(p1,NULL));
//     CHECK_NOTHROW(Game game(NULL,p1));
// }
//6
TEST_CASE("Play turn")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_NOTHROW(game.playTurn());

}
//7
TEST_CASE("Stack sizes after turn")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playTurn();
    
    CHECK(p1.stacksize()==p2.stacksize());
    CHECK(50>=p1.stacksize()+p2.stacksize());
    
    
   
}
//8
// TEST_CASE("Just one player win in every turn")//****** We don't have an implementation so it does an infinite loop******
// {
//     Player p1("Alice");
//     Player p2("Bob");
//     Game game(p1,p2);
//     int p1_ct=0;
//     int p2_ct=0;

//     //while (p1.stacksize()!=0 && p2.stacksize()!=0)
//     {
//         game.playTurn();
//         bool x=((p1_ct+1)==p1.cardesTaken()&&p2_ct==p2.cardesTaken());
//         bool y=((p2_ct+1)==p2.cardesTaken()&&p1_ct==p1.cardesTaken());
//         CHECK_FALSE( !(x||y));
//         if(p1_ct==p1.cardesTaken())
//         {
//             p2_ct++;
//         }
//         else 
//         {
//             p1_ct++;
//         }
//     }


// }
//9
TEST_CASE("Play all")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_NOTHROW(game.playAll());


}
//10
TEST_CASE("There is a winner")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();

    bool x=(p1.cardesTaken()>p2.cardesTaken());
    bool y=(p1.cardesTaken()<p2.cardesTaken());
    CHECK_FALSE(!(x ||y));
}
//11
TEST_CASE("The amount of winning after a few turns")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

   for (int i = 0; i < 5; i++)
   {
        game.playTurn();
   }
   
    CHECK(5-p1.cardesTaken()==p2.cardesTaken());
}
//12
TEST_CASE("The players has no cardes after a game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();


    CHECK(p2.stacksize()==0);

    CHECK(p1.stacksize()==0);


}
//13
TEST_CASE("Print last turn at beginning of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_NOTHROW(game.printLastTurn());
}
//14
TEST_CASE("Print winer at beginning of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_NOTHROW(game.printWiner());
}
//15
TEST_CASE("Print log at beginning of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_NOTHROW(game.printLog());
}
//16
TEST_CASE("Print stats turn at beginning of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_NOTHROW(game.printStats());
}
//17
TEST_CASE("Print last turn at the end")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();

    CHECK_NOTHROW(game.printLastTurn());
}
//18
TEST_CASE("Print winer at the end")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();

    CHECK_NOTHROW(game.printWiner());
}
//19
TEST_CASE("Print log at the end")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();

    CHECK_NOTHROW(game.printLog());
}
//20
TEST_CASE("Print stats turn at the end")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();

    CHECK_NOTHROW(game.printStats());
}

