#include "sword.hpp"
#include "../player.hpp"

CSword::CSword (const std::string & n_name, const int & n_size, const int & n_id, const int parameter, const bool n_equip ) : CItems( n_name, n_size, n_id, parameter, n_equip ) {};

CSword::~CSword() = default;

CItems* CSword::clone() const {
    return new CSword ( *this );
} 

std::ostream& CSword::printInfo (std::ostream & os ) {
    return os << "Info about sword :" << this->item_name << std::endl << "Size: " << this->size << std::endl << "Damage: " << this->unique_parameter << std::endl;
}

CSword& CSword::itemUsage ( CPlayer & obj ) {

    if( obj.getEquipdamage() != 0 && !equip){
        system( "clear ");

        char tmp = 0;
        std::cout << "You have equipped sword already!" << std::endl << "Enter something to continue" << std::endl;
        std::cin >> tmp;
    }

    if( equip ){
        obj.setEquipDamage( 0 );
        equip = false;
    }
    else{
        obj.setEquipDamage ( unique_parameter );
        equip = true;
    }

    return *this;
}
