#ifndef SWORD_H
#define SWORD_H
#include "items.hpp"

///Sword inherited from Items
class CSword : public CItems {
    public:
    CSword ( const std::string & n_name, const int & n_size, const int & n_id, const int parameter = 0 , const bool n_equip = false );
    ~CSword() override;

    CItems* clone() const override;
    std::ostream& printInfo (std::ostream & os ) override;
    ///set the equip_damage on player, player can't use more than one sword in the same time
    CSword& itemUsage ( CPlayer & obj ) override;

};
#endif