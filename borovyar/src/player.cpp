#include "player.hpp"

CPlayer::CPlayer( const int & n_x, const int & n_y,  const int n_health, const int n_level, const int n_damage ,
        const int  n_progress, const char n_direction, const int n_equip_damage) : m_x ( n_x ), m_y ( n_y ), health ( n_health ), player_damage ( n_damage ),
             level ( n_level), direction (n_direction), progress(n_progress), equip_damage ( n_equip_damage), m_backpack( new CBack_pack ()) {}

CPlayer::~CPlayer() {
    m_backpack->clearItems();
    delete m_backpack;
}

int CPlayer::getPosX() const{
    return this->m_x;
}

int CPlayer::getPosY() const {
    return this->m_y;
}

int CPlayer::getHealth () const{
    return this->health;
}

int CPlayer::getDamage() const{
    return this->player_damage;
}

int CPlayer::getLevel() const{
    return this->level;
}

int CPlayer::getEquipdamage() const{
    return equip_damage;
}

char CPlayer::getDirection() const{
    return this->direction;
}

size_t CPlayer::getSizeBackPack() const{
    return m_backpack->getOveralSize();
}

size_t CPlayer::getCurrentBackPack() const{
    return m_backpack->getTmpSize();
}

CPlayer& CPlayer::treatment( const int & plus_to_health){
    this->health += plus_to_health;
    if (this->health > 100 )
        this->health = 100;
    return *this;
}

CPlayer& CPlayer::suffer_damage( const int & minus_to_health){
    this->health -= minus_to_health;
    if (this->health < 0 )
        this->health = 0;
    return *this;
}

CPlayer& CPlayer::level_up(){
    this->level += 1;
    this->player_damage += 3;
    m_backpack->increaseSize();
    return *this;
}

CPlayer& CPlayer::increaseDamage( const int & new_damage ){
    this->player_damage += new_damage;
    return *this;
}

CPlayer& CPlayer::increasePotionDamage( const int & new_damage ){
    this->player_damage += new_damage;
    return *this;
}

CPlayer& CPlayer::decreaseDamage( const int & new_damage ){
    this->player_damage -= new_damage;
    if( this->player_damage < 0 ) 
        this->player_damage = 0;
    return *this;
}

CPlayer& CPlayer::setEquipDamage ( const int new_damage ){
    equip_damage = new_damage;
    return *this;
}

CPlayer& CPlayer::changeDirection( const char & new_direction ){
    this->direction = new_direction;
    return *this;
}

CPlayer& CPlayer::increaseExperience( const int & experience ){
    this->progress += experience;
    while( this->progress >= 100 ){
        this->progress -= 100;
        this->level_up();
    }
    return *this;
}

CPlayer& CPlayer::addItem ( CItems * n_item ){
    m_backpack->addItem( n_item );
    return *this;
}

CPlayer& CPlayer::openBackPack ( ){
    char tmp = 0;

    while ( 1 ){
        system("clear");

        m_backpack->printInfoPlayer( std::cout );

        std::cout << "Choose item ( enter number ) : ( Q to exit )" << std::endl;
        std::cin >> tmp;
        tmp = std::tolower ( tmp );

        if( tmp == 'q' ){
            break;
        }
        else if ( tmp - '0' <= 0 || (size_t)(tmp - '0') > m_backpack->getSize()){
            system ( "clear" );
            char out_of_range;
            std::cout << "Out of the range" << std::endl << "Enter something to continue:" << std::endl;
            std::cin >> out_of_range;
        }
        else{
            char tmp2 = 0;

            while( 1 ){
                system("clear");

                m_backpack->getItemInfo( std::cout, tmp - '0' );

                std::cout << "E ( use ) / D ( delete item ) : ( Q to exit )" << std::endl;
                std::cin >> tmp2;
                tmp2 = std::tolower ( tmp2 );

                if( tmp2 == 'q' ){
                    break;
                }
                if( tmp2 == 'e'){
                    (*m_backpack)[tmp - '0']->itemUsage(*this);

                    if( (*m_backpack)[ (tmp - '0')]->getUsed() ){
                        (*m_backpack).delItem( tmp - '0');
                    }

                    break;
                }
                if( tmp2 == 'd' ){
                    if( (*m_backpack)[ tmp - '0' ]->getId() == 1 ){
                        equip_damage = 0;
                    }

                    (*m_backpack).delItem( tmp - '0');
                    break;
                }
            }
        }
    }

    return *this;
}

CPlayer& CPlayer::setBackPack ( CBack_pack * obj ){
    if( m_backpack != nullptr ){
        m_backpack->clearItems();
    }

    delete m_backpack;
    m_backpack = obj;

    return *this;
}

std::ostream & operator << ( std::ostream & os, const CPlayer & obj) {
    return os << "Health: " << obj.health << std::endl 
                << "Damage: " << obj.player_damage + obj.equip_damage << std::endl 
                << "Level: " << obj.level << std::endl
                << "Experience: " << obj.progress << std::endl;
}

void CPlayer::saveProgress ( std::ofstream& save_file_player, std::ofstream& save_file_backpack ){
    save_file_player << health << std::endl << player_damage << std::endl << equip_damage << std::endl << level << std::endl << progress << std::endl << m_x << std::endl << m_y << 
        std::endl << direction;
    
    m_backpack->saveProgress( save_file_backpack );
}

CPlayer& CPlayer::movement(const int& new_x, const int& new_y, const char& new_image){
    m_x = new_x;
    m_y = new_y;
    direction = new_image;
    return *this;
}