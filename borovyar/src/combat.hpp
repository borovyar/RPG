#ifndef COMBAT_H
#define COMBAT_H
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <memory>

#include "player.hpp"

#include "enemies/enemies.hpp"
#include "enemies/boar.hpp"
#include "enemies/pank.hpp"
#include "enemies/dragon.hpp"
#include "enemies/soldier.hpp"
#include "enemies/boss.hpp"


///Combat
///Main idea:
///Accept pointers to the player and enemy as parameters. Decrease health and print some dialog between them;

class CCombat{
public:
    ///Construcutor
    CCombat( CPlayer * player, CEnemies* enemie);
    ///Destructor
    virtual ~CCombat();

    ///Actual "fight" between player and enemy ( player and enemy receive damage ), print dialog
    bool combat();
    ///Resulting fight and if player won return true
    bool win( const int& p_health, const int& e_health );
    
private:
    std::vector<std::string> happines = {"I COMPILE THIS FILE!", "MEM LEAKS CAN'T DEFEAT ME!", "IT IS NOT YOUR DAY, PROGTEST",
                                            "I HEARD SOMETHING ABOUT F, IT IS THE 6TH LETTER IN ALPHABET", "TODAY'S CONTEST HOMEWORK IS TO EASY FOR MY SWORD",
                                            "EASY-PEASY, LEMON SQUEEZY"};
    std::vector<std::string> defeat = {"DNES, PANE KOLEGO, MATE F", "OPAKUJTE", "PA2 IS HARD, I SKIP THIS CLASS", "#include namespace std;"};
    std::vector<std::string> attack = {"PIU-PIU", "UAAA!!!", "TA, SHA", "BRAAA!!", "LOWKICK!"};
    std::vector<std::string> middle = {"NEXT TIME I WILL USE STL", "YOU ARE TO FAST BECAUSE OF HASH MAPS", "VALGRIND WILL HELP ME", "NICE TRY, BUT DEBUGGER DETECT YOU"};                                 
    CPlayer * m_player;
    CEnemies * m_enemie;
};

#endif