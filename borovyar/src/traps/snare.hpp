#ifndef SNARE_H
#define SNARE_H
#include "trap.hpp"

///Snare is inherited from Trap
class CSnare : public CTrap{
    public:
    CSnare(const int& n_x, const int& n_y, const int& new_damage = 0);
    ~CSnare () override;   

    CTrap* clone() const override;
    ///Decrease damage of the player
    CSnare& effectOnPlayer ( CPlayer & obj ) override;
    void saveTrap( std::ofstream& save_file ) override;
};

#endif