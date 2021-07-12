#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "inventory.hpp"
 
///    Player:
///    Main idea:
///    Class has standart attributes for the player in RPG game and backpack. The other methods I found out useful
///    for the interplay with world and for the backpack using.


class CPlayer{
    public:
    ///Construcutor
    CPlayer ( const int & n_x, const int & n_y,  const int n_health = 100, const int n_level = 1, const int n_damage = 1,
        const int n_progress = 0, const char n_direction = '>', const int n_equip_damage = 0);
    ///Destructor
    virtual ~CPlayer();

    ///get x
    int getPosX() const;
    ///get y
    int getPosY() const;
    ///get health
    int getHealth() const;
    ///get player_damage
    int getDamage() const;
    ///get level
    int getLevel() const;
    ///get equip_damage
    int getEquipdamage() const;
    ///get direction
    char getDirection() const;
    ///get m_size in backpack
    size_t getSizeBackPack() const;
    ///get m_tmp_size in backpack
    size_t getCurrentBackPack() const;

    //set backpack
    CPlayer& setBackPack ( CBack_pack * obj );
    //set equip_damage
    CPlayer& setEquipDamage ( const int new_damage );

    ///heal himself
    CPlayer& treatment( const int & plus_to_health );
    ///player got damage
    CPlayer& suffer_damage( const int & minus_to_health );
    ///increase level, player_damage, size of backpack if expereince is bigger than, or equal 100
    CPlayer& level_up();
    ///increase player_damage, using exectly for the potion usage ( same method as increaseDamage, I created for the my comfrot )
    CPlayer& increasePotionDamage( const int & new_damage );
    ///increase player_damage
    CPlayer& increaseDamage( const int & new_damage );
    ///decrease player_damage
    CPlayer& decreaseDamage( const int & new_damage );
    ///change the image of player (>, <, ^)
    CPlayer& changeDirection ( const char & new_direction );
    ///increase exprience, if exeprience >= 100, than level_up()
    CPlayer& increaseExperience( const int & new_damage );
    ///change coordinates of the player on map
    CPlayer& movement(const int& new_x, const int& new_y, const char& new_image);
    ///add item to the backpack
    CPlayer& addItem ( CItems * n_item );
    ///open menu in backpack, player can choose item to use it or delete from the backpack
    CPlayer& openBackPack ( );
    ///print attributes of the player in ostream
    friend std::ostream & operator << ( std::ostream & os, const CPlayer & obj );

    ///save attributes and backpack of the player
    void saveProgress ( std::ofstream& save_file_player, std::ofstream& save_file_backpack );

    private:
    int health, level, progress, player_damage = 0, equip_damage = 0;
    int m_x, m_y;
    char direction;
    CBack_pack* m_backpack;
};
#endif