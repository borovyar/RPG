#include "potionH.hpp"
#include "../player.hpp"

CPotionH::CPotionH (const std::string & n_name, const int & n_size, const int & n_id, const int parameter ) : CItems( n_name, n_size, n_id, parameter ) {};

CPotionH::~CPotionH() = default;

CItems* CPotionH::clone() const {
    return new CPotionH ( *this );
}

std::ostream& CPotionH::printInfo (std::ostream & os ) {
    return os << "Info about treat potion " << this->item_name << ":" << std::endl << "Size: " << this->size << std::endl << "Treat: " << this->unique_parameter << std::endl;
}
    
CPotionH& CPotionH::itemUsage ( CPlayer & obj ) {
    obj.treatment(this->unique_parameter);
    this->used = true;
    return *this;
}