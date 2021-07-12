#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <vector>
#include <fstream>

#include "items/items.hpp"
#include "items/sword.hpp"
#include "items/potionH.hpp"
#include "items/potionD.hpp"
#include "items/potionL.hpp"

/// Inventory
///   Main idea:
///   Inventory has vector of items in private, size of inventory. Main methods helps to add, delete, use items in vector. 
///   Inventory uses generally in CPlayer and CChest;
class CBack_pack{
    public:
    ///Construcutor
    CBack_pack( const int& n_size = 10, const int& n_tmp = 0);  
    ///Copy Constructor
    CBack_pack ( const CBack_pack& other );
    ///Assigment Operator
    CBack_pack& operator = ( CBack_pack other );
    ///Destructor
    virtual ~CBack_pack();

    ///add item to the unsorted vector
    CBack_pack& addItem( CItems * obj);
    ///delete item froms the unsorted vector
    CBack_pack& delItem( const int & pos );
    ///increase m_size on some value*/
    CBack_pack& increaseSize( );
    ///clear items in the vector ( for the loading from the savings )
    CBack_pack& clearItems ();
    ///subscription operator
    CItems* operator [] ( const int & pos );
    ///print info in "playerstyle" (as backpack)
    std::ostream& printInfoPlayer(std::ostream& os);
    ///print info in "cheststyle" (as inventory inside chest)
    std::ostream& printInfoChest(std::ostream& os);
    ///print info in about item which player chose
    std::ostream& getItemInfo ( std::ostream& os, const int & pos );
    ///save invetory in file
    void saveProgress ( std::ofstream& save_file );

    ///get my_items.size()
    size_t getSize () const;
    ///get m_size
    int getOveralSize () const;
    ///get m_tmp_size
    int getTmpSize () const;

    private:
    int m_size;
    int m_tmp_size;
    std::vector<CItems*> my_items;
};
#endif