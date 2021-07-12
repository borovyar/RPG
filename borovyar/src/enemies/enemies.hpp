#ifndef ENEMIES_H
#define ENEMIES_H
#include <iostream>
#include <fstream>
#include <memory>

///Enemies
///Main idea:
///Create different types of the enemies. Player will figth with them and recieve some exeprience;

class CEnemies{
protected:
    int health, damage, experience;
    int m_x, m_y;
    char image;
public:
    ///Constructor
    CEnemies( const int & n_x, const int & n_y, const int n_heath = 0, const int n_damage = 0, const int n_experience = 0, 
                const char n_image = 0 );
    ///Copy Constructor
    CEnemies ( const CEnemies & other );
    ///Destructor
    virtual ~CEnemies() = default;

    ///get health
    int getHealth() const;
    ///get damage
    int getDamage() const;
    ///get experience
    int getExperience() const;
    ///get image
    char getImage() const;
    ///get y
    int getPosY() const;
    ///get x
    int getPosX() const;

    ///set damage
    CEnemies& setDamage (const int & n_damage);
    ///set health
    CEnemies& setHealth(const int & n_health);
    ///set experience
    CEnemies& setExperience (const int & n_experience);
    ///set image
    CEnemies& setImage (const char & n_image);

    ///make clone of enemie via copy constructor
    virtual std::shared_ptr <CEnemies> clone () const = 0;
    ///print attributes in ostream   
    virtual std::ostream & printInfo (std::ostream & os) = 0;
    ///get damage, decrease health
    CEnemies& suffer_damage( const int & minus_to_health );
    ///save enemy in save_file
    void saveEnemie( std::ofstream& file );
};

#endif