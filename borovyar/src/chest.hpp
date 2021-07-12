#ifndef CHEST_H
#define CHEST_H
#include <set>
#include <iostream>
#include <iomanip>
#include "player.hpp"

class CPlayer;
///Chest
///Main idea:
///The chest would have inventory inside and player should figure out the password from the some mystery,
///then player can add items in the his inventory; 


class CChest {
    public:
    ///Construcutor
    CChest ( const int& n_x, const int& n_y, CBack_pack* n_item,  std::set<std::string>& n_answers, const std::string & n_mystery, bool n_opened = false );
    ///Destructor
    virtual ~CChest();

    ///Inventory inside the chest become aviable for the player, player can add items to his inventory
    CChest& openBackPack ( CPlayer* obj );
    ///Proccess of the figuring out the password from the mystery
    CChest& openChest( CPlayer * obj );
    ///Clean inventory of the chest ( generally, before load saving )
    CChest& clearChest ( );

    ///get opened
    bool getOpened () const;
    ///get in fact items.empty() 
    bool Empty() const;
    ///get x
    int getX() const;
    ///get y
    int getY() const;

    ///print info about chest, how many is in it
    void getInfo ( std::ostream& os );
    ///save chest to the file
    void saveChest ( std::ofstream& save_file );

    private:
    int m_x, m_y;
    bool opened;
    std::string mystery;
    std::set<std::string> answers;
    CBack_pack* items; //inventory inside the chest
};
#endif