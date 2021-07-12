#include "bomb.hpp"
#include "../player.hpp"

CBomb::CBomb(const int& n_x, const int& n_y, const int& new_damage) :  CTrap(n_x, n_y, new_damage) {};

CBomb::~CBomb () = default;

CTrap * CBomb::clone() const {
    return new CBomb ( *this );
}

CBomb& CBomb::effectOnPlayer ( CPlayer & obj ){
    obj.suffer_damage(this->damage);
    return *this;
}

void CBomb::saveTrap( std::ofstream& save_file ){
    save_file << 1 << std::endl << m_x << std::endl << m_y << std::endl << damage << std::endl;
}
