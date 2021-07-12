#ifndef ITEMS_H
#define ITEMS_H
#include <memory>
#include <iostream>

///Items
///Main idea:
///Create items ( in my implementation I have swords and poitions ) with different attributes and usage;
///They would be in chests and in inventory of the player;

class CPlayer;
class CItems{
    public:
    ///Constructor
    CItems( const std::string & n_name, const int & n_size, const int & n_id, const int parameter = 0, const bool n_equip = false );
    ///Copy Constructor
    CItems ( const CItems & other );
    ///Destructor
    virtual ~CItems ();

    ///make clone via copy constructor
    virtual CItems* clone( ) const = 0;
    ///print info about attributes
    virtual std::ostream& printInfo ( std::ostream& os  ) = 0;
    ///usage on the player
    virtual CItems& itemUsage ( CPlayer & obj ) = 0;

    ///get used
    bool getUsed() const;
    ///get equip
    bool getEquip() const;
    ///get id
    int getId() const;
    ///get size
    int getSize() const;
    ///get name
    std::string getName() const;
    ///get unique_parameter
    int getParameter() const;

    protected:
    bool used  = false, equip = false;
    std::string item_name;
    int size, id;
    int unique_parameter;
};
#endif