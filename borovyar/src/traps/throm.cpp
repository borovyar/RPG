#include "throm.hpp"
#include "../player.hpp"

CThorm::CThorm(const int& n_x, const int& n_y, const int& new_damage) :  CTrap(n_x, n_y, new_damage){};

CThorm::~CThorm() = default;

CTrap* CThorm::clone() const{
    return new CThorm (*this);
}

CThorm& CThorm::effectOnPlayer ( CPlayer & obj ){
    obj.decreaseDamage(this->damage);
    obj.suffer_damage(this->damage);
    return *this;
}

void CThorm::saveTrap( std::ofstream& save_file ){
    save_file << 3 << std::endl << m_x << std::endl << m_y << std::endl << damage << std::endl;
}