#ifndef POTIONL_H
#define POTIONL_H
#include "items.hpp"

///PotionL inherited from Items
class CPotionL : public CItems {
    public:
    CPotionL ( const std::string & n_name, const int & n_size, const int & n_id, const int parameter = 0 );
    ~CPotionL() override;

    CItems* clone() const override;
    std::ostream& printInfo (std::ostream & os ) override;
    ///increase experience of the player
    CPotionL& itemUsage ( CPlayer & obj ) override;

};

#endif