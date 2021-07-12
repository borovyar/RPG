#ifndef BOMB_H
#define BOMB_H
#include "trap.hpp"

///Bomb is inherited from Trap
class CBomb : public CTrap {
    public:

    CBomb(const int& n_x, const int& n_y, const int& new_damage = 0);
    ~CBomb () override;

    CTrap*  clone() const override;
    ///Decrease damage of the player
    CBomb& effectOnPlayer ( CPlayer & obj ) override;
    void saveTrap( std::ofstream& save_file ) override;
};

#endif