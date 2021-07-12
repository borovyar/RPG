#ifndef PANK_H
#define PANK_H
#include "enemies.hpp"

///Pank inherited from Enemies
class CPunk : public CEnemies {
    public:
    CPunk( const int & n_x, const int & n_y, const int & n_heath, const int & n_damage, const int & n_experience, const char& n_image  );
    ~CPunk() override = default;

    std::shared_ptr <CEnemies> clone () const override; 
    std::ostream & printInfo (std::ostream & os) override;
};
#endif