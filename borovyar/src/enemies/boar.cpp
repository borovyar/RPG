#include "boar.hpp"

CBoarW140::CBoarW140( const int & n_x, const int & n_y, const int n_heath, const int n_damage, const int n_experience, const char n_image ) : 
                CEnemies(n_x, n_y, n_heath, n_damage, n_experience, n_image) {};

std::shared_ptr <CEnemies> CBoarW140::clone () const{
    return std::make_shared<CBoarW140>(*this);
}

std::ostream & CBoarW140::printInfo (std::ostream & os){
    return os << "Type of Enemy: Boar" << std::endl << "Image: " << this->getImage() << std::endl << "Health: " << this->getHealth() << std::endl << "Damage: " << this->getDamage()
        << std::endl << "Experience to get: " << this->getExperience() << std::endl;
}