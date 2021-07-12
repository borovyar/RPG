#ifndef POTIONH_H
#define POTIONH_H
#include "items.hpp"

///PotionH inherited from Items
class CPotionH : public CItems {
    public:
    CPotionH ( const std::string & n_name, const int & n_size, const int & n_id, const int parameter = 0 );
    ~CPotionH() override;

    CItems* clone() const override;
    std::ostream& printInfo (std::ostream & os ) override;
    ///heal player
    CPotionH& itemUsage ( CPlayer & obj ) override;

};

#endif