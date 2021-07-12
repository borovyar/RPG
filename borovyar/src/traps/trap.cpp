#include "trap.hpp"
#include "../player.hpp"

CTrap::CTrap(const int& n_x, const int& n_y, const int& new_damage) :  m_x(n_x), m_y(n_y), damage(new_damage){};

CTrap::CTrap ( const CTrap & other ){
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    this->damage = other.damage;
}

CTrap::~CTrap() = default;

int CTrap::getPosX () const {
    return m_x;
}

int CTrap::getPosY () const {
    return m_y;
}

int CTrap::getDamage () const {
    return damage;
}

