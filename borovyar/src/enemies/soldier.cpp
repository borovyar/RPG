#include "soldier.hpp"
CSoldier::CSoldier( const int & n_x, const int & n_y, const int & n_heath, const int & n_damage, const int & n_experience, const char& n_image ) : 
                CEnemies(n_x, n_y, n_heath, n_damage, n_experience, n_image) {};

std::shared_ptr <CEnemies> CSoldier::clone () const{
    return std::make_shared<CSoldier>(*this);
}

std::ostream & CSoldier::printInfo (std::ostream & os){
    return os << "Type of Enemy: Soldier" << std::endl << "Image: " << this->getImage() << std::endl << "Health: " << this->getHealth() << std::endl << "Damage: " << this->getDamage()
        << std::endl << "Experience: " << this->getExperience() << std::endl;
}