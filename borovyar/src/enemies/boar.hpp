#ifndef BOAR_H
#define BOAR_H
#include "enemies.hpp"

///Boar inherited from Enemies
class CBoarW140 : public CEnemies{
    public:
    CBoarW140( const int & n_x, const int & n_y, const int n_heath = 0, const int n_damage = 0, const int n_experience = 0, const char n_image = 0 );
    ~CBoarW140() override = default;
    
    std::shared_ptr <CEnemies> clone () const override; 
    std::ostream & printInfo (std::ostream & os) override;

};
#endif