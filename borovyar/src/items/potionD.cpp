#include "potionD.hpp"
#include "../player.hpp"

CPotionD::CPotionD (const std::string & n_name, const int & n_size, const int & n_id, const int parameter ) : CItems( n_name, n_size, n_id, parameter ) {};

CPotionD::~CPotionD() = default;

CItems* CPotionD::clone() const {
    return new CPotionD ( *this );
}

std::ostream& CPotionD::printInfo (std::ostream & os ) {
    return os << "Info about damage potion " << this->item_name << ":" << std::endl << "Size: " << this->size << std::endl << "Damage to give: " << this->unique_parameter << std::endl;
}
    
CPotionD& CPotionD::itemUsage ( CPlayer & obj ) {
    obj.increasePotionDamage(this->unique_parameter);
    this->used = true;
    return *this;
}