#ifndef TRAP_H
#define TRAP_H
#include <iostream>
#include <memory>
#include <fstream>

///Trap
///Main idea:
///Create a traps with different effect on player; 
///Traps are disappeared after sprunging;

class CPlayer;
class CTrap{
    public:
    ///Construcutor,
    CTrap(const int& n_x, const int& n_y, const int& new_damage = 0);
    ///Copy Construcutor
    CTrap ( const CTrap & other );
    ///Destructor
    virtual ~CTrap ();

    ///get x
    int getPosX () const ;
    ///get y
    int getPosY () const ;
    ///get damage
    int getDamage () const ;

    ///save trap in save_file
    virtual void saveTrap( std::ofstream& save_file ) = 0;   
    ///make clone of the trap via copy constructor 
    virtual CTrap* clone () const = 0;
    ///interplay with player
    virtual CTrap& effectOnPlayer ( CPlayer & obj ) = 0;
    
    protected:
    int m_x, m_y, damage;
};

#endif