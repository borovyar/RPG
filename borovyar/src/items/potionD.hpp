#ifndef POTIOND_H
#define POTIOND_H
#include "items.hpp"

///PotionD inherited from Items
class CPotionD : public CItems {
    public:
    CPotionD ( const std::string & n_name, const int & n_size, const int & n_id, const int parameter = 0 );
    ~CPotionD() override;

    CItems* clone() const override;
    std::ostream& printInfo (std::ostream & os ) override;
    ///Increase player_damage of the player
    CPotionD& itemUsage ( CPlayer & obj ) override;

};

#endif