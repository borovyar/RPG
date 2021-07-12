#ifndef GAME_H
#define GAME_H
#include "chest.hpp"
#include "combat.hpp"

#include "traps/trap.hpp"
#include "traps/bomb.hpp"
#include "traps/snare.hpp"
#include "traps/throm.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

///Game
///Main idea:
///Idea is that game running and printing, main menu, map and e.g.
///Also Game has methods to save/load levels, characters, progress;


class CGame{
    public:
    ///Constructor
    CGame( std::vector<std::vector<char>>& map );
    ///Destructor
    virtual ~CGame ();
    
    ///set new player
    CGame& setPlayer( CPlayer * player );

    ///stop the running game
    CGame& stopGame();
    ///stop the termination of the app
    CGame& endApp();
    ///run game
    CGame& runGame();

    ///add enemy in the enemy-vector
    CGame& addEnemie( CEnemies * enemie = nullptr );
    ///add chest in the enemy-vector ( depends on the level_flag )
    CGame& addChest( const int& x, const int& y );
    ///add chest in the enemy-vector
    CGame& addChest( CChest * chest = nullptr );
    ///add trap in the enemy-vector ( depends on the level_flag )
    CGame& addTrap ( const int& x, const int& y);
    ///add trap in the enemy-vector
    CGame& addTrap ( CTrap* trap = nullptr );

    ///load player, his progress in game
    CGame& readProgress ( );
    ///load inventory of the player
    CGame& readBackPack ( );
    ///load level on which player saved game
    CGame& readCurrentWorld ( );
    ///load whole enemies
    CGame& readEnemie ( );
    ///load whole traps
    CGame& readTrap ( );
    ///load whole chests
    CGame& readChest ( );
    ///delete whole pointers in the vectors of characters ( enemy, chest, trap ), before loading savings
    CGame& cleanCharacters( );
    ///method specify choice of the game ( interplay, moving, open backpack, travel, get info ) 
    CGame& Movement ( const char& m_movement );
    ///method for the interplay with trap
    CGame& trapUsing ( const int& x, const int&y  );

    ///load new game ( from 1st level )
    void newGame( );
    ///load saved game
    void loadSavedGame( );
    ///save everything such as progress of the player, levels, characters
    void saveGame( );
    ///save current level
    void saveLevel( );
    ///save whole enemies
    void saveEnemies(  );
    ///save whole chests
    void saveChest( );
    ///save whole traps
    void saveTrap ( );
    ///save player progress
    void savePlayer ( );
    ///load new next level
    void loadNewLevel( );
    ///load saved previous level
    void loadPreviousLevel( );
    void loadNextLevel ( );
    ///load saved next level
    void loadCurrentLevel ( );
    ///print main menu with options
    void printMenu(std::ostream& os);
    ///specify choice in main menu
    void specifyChoice (const char& choice);
    ///draw the map with characters, player on it
    void drawMap ( );
    
    ///get gameOn
    bool getGameOn() const;
    ///get End
    bool getEnd() const;

    ///return true if detect something ( enemy, chest, travel option ) around player
    bool detected(char& check);
    
    private:
    int progress_flag, level_flag;
    std::vector<std::string> m_savings = { "src/savings_progress/saveProgress.txt", "src/savings_progress/saveBackPack.txt", "src/savings_progress/saveWorld.txt"};
    std::vector<std::string> m_levels = { "src/new_levels/level1.txt", "src/new_levels/level2.txt", "src/new_levels/level3.txt", "src/new_levels/level4.txt", "src/new_levels/level5.txt" };
    std::vector<std::string> levels_save = { "src/savings_levels/level1World.txt",  "src/savings_levels/level2World.txt", "src/savings_levels/level3World.txt", "src/savings_levels/level4World.txt", "src/savings_levels/level5World.txt"};
    std::vector<std::string> characters_save = { "src/savings_characters/saveEnemies.txt", "src/savings_characters/saveChests.txt", "src/savings_characters/saveTraps.txt"};
    CPlayer * m_player = nullptr;
    std::vector<CEnemies*>  m_enemie;
    std::vector<CChest*> m_chest;
    std::vector<CTrap *> m_trap;
    std::vector<std::vector<char>> m_map;
    bool gameOn, End;
};
#endif