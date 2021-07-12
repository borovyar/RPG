#include "pank.hpp"
CPunk::CPunk( const int & n_x, const int & n_y, const int & n_heath, const int & n_damage, const int & n_experience, const char& n_image ) : 
                CEnemies(n_x, n_y, n_heath, n_damage, n_experience, n_image) {};

std::shared_ptr <CEnemies> CPunk::clone () const{
    return std::make_shared<CPunk>(*this);
}

std::ostream & CPunk::printInfo (std::ostream & os){
    return os << "Type of Enemy: Punk" << std::endl << "Image: " << this->getImage() << std::endl << "Health: " << this->getHealth() << std::endl << "Damage: " << this->getDamage()
        << std::endl << "Experience: " << this->getExperience() << std::endl;
}