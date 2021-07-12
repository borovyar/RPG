#ifndef THROM_H
#define THROM_H
#include "trap.hpp"

///Thorm is inherited from Trap
class CThorm : public CTrap{
    public:
    
    CThorm(const int& n_x, const int& n_y, const int& new_damage = 0);
    ~CThorm () override;

    CTrap* clone() const override;
    ///Decrease health and damage of the player
    CThorm& effectOnPlayer ( CPlayer & obj ) override;
    void saveTrap( std::ofstream& save_file ) override;
};

#endif