#ifndef DRAGON_H
#define DRAGON_H
#include "enemies.hpp"

///Dragon inherited from Enemies
class CDragon : public CEnemies{
    public:
    CDragon( const int & n_x, const int & n_y, const int & n_heath, const int & n_damage, const int & n_experience, const char& n_image  );
    ~CDragon() override = default;

    std::shared_ptr <CEnemies> clone () const override; 
    std::ostream & printInfo (std::ostream & os) override;
};
#endif