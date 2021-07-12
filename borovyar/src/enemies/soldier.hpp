#ifndef SOLDIER_H
#define SOLDIER_H
#include "enemies.hpp"

///Soldier inherited from Enemies

class CSoldier : public CEnemies{
    public:
    CSoldier( const int & n_x, const int & n_y, const int & n_heath, const int & n_damage, const int & n_experience, const char& n_image );
    ~CSoldier() override = default;

    std::shared_ptr <CEnemies> clone () const override; 
    std::ostream & printInfo (std::ostream & os) override;
};
#endif