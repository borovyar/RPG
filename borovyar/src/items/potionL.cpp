#include "potionL.hpp"
#include "../player.hpp"
CPotionL::CPotionL(const std::string & n_name, const int & n_size, const int & n_id, const int parameter ) : CItems( n_name, n_size, n_id, parameter ) {};

CPotionL::~CPotionL() = default;

CItems*CPotionL::clone() const {
    return new CPotionL ( *this );
}

std::ostream& CPotionL::printInfo (std::ostream & os ) {
    return os << "Info about level potion " << this->item_name << ":" << std::endl << "Size: " << this->size << std::endl << "Experience to recieve: " << this->unique_parameter << std::endl;
}
    
CPotionL& CPotionL::itemUsage ( CPlayer & obj ) {
    obj.increaseExperience( this->unique_parameter );
    this->used = true;
    return *this;
}