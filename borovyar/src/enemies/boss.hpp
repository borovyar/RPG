#ifndef BOSS_H
#define BOSS_H
#include "enemies.hpp"

///Boss inherited from Enemies
class CBoss : public CEnemies {
    public:
    CBoss( const int & n_x, const int & n_y, const int & n_heath, const int & n_damage, const int & n_experience, const char& n_image );
    ~CBoss() override = default;

    std::shared_ptr <CEnemies> clone () const override; 
    std::ostream & printInfo (std::ostream & os) override; 
};

#endif