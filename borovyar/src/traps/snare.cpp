#include "snare.hpp"
#include "../player.hpp"

CSnare::CSnare(const int& n_x, const int& n_y, const int& new_damage) :  CTrap(n_x, n_y, new_damage){};

CSnare::~CSnare () = default;

CTrap* CSnare::clone() const{
    return new CSnare (*this);
}

CSnare& CSnare::effectOnPlayer ( CPlayer & obj ){
    obj.decreaseDamage(this->damage);
    return *this;
}

void CSnare::saveTrap( std::ofstream& save_file ){
    save_file << 2 << std::endl << m_x << std::endl << m_y << std::endl << damage << std::endl;
}