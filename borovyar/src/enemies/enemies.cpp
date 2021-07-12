#include "enemies.hpp"

CEnemies::CEnemies( const int & n_x, const int & n_y, const int n_heath, const int n_damage, const int n_experience, 
                const char n_image) : 
                m_x( n_x ), m_y( n_y ), health( n_heath ), damage( n_damage ), experience( n_experience ), image ( n_image ) {};
CEnemies::CEnemies ( const CEnemies & other) : health (other.health), damage (other.damage), experience (other.experience) {};

int CEnemies::getHealth() const { 
    return health;
}

int CEnemies::getDamage() const { 
    return damage; 
}

int CEnemies::getExperience() const {
    return experience;
}

char CEnemies::getImage() const{
    return image;
}

int CEnemies::getPosY() const{
    return m_y;
}

int CEnemies::getPosX() const{
    return m_x;
}

CEnemies& CEnemies::setDamage (const int & n_damage){
    damage = n_damage;
    return *this;
}

CEnemies& CEnemies::setHealth(const int & n_health){
    health = n_health;
    return *this;
}

CEnemies& CEnemies::setExperience (const int & n_experience){
    experience = n_experience;
    return *this;
}

CEnemies& CEnemies::setImage (const char & n_image){
    image = n_image;
    return *this;
}

CEnemies& CEnemies::suffer_damage( const int & minus_to_health ){ 
    this->health -= minus_to_health;
    if( this->health < 0 )
        health = 0;
    return *this;
}

void CEnemies::saveEnemie( std::ofstream& file ){
    file << health << std::endl << damage << std::endl << experience << std::endl << image << std::endl << m_x << std::endl << m_y;
}