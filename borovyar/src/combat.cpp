#include "combat.hpp"

CCombat::CCombat(CPlayer * player, CEnemies* enemie ) : m_player ( player ), m_enemie ( enemie ) {};

CCombat::~CCombat() = default;

bool CCombat::combat(){
    char tmp = 0;

    m_player->suffer_damage( m_enemie->getDamage());
    m_enemie->suffer_damage( m_player->getDamage() + m_player->getEquipdamage());

    system ("clear");

    std::this_thread::sleep_for(std::chrono::milliseconds(330) );
    std::cout << attack[(rand() % attack.size())] << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(130) );
    std::cout << "You damage enemie on " << m_player->getDamage() << "pt" << std::endl << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(330) );
    std::cout << attack[(int)(rand() % attack.size())] << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(130) );
    std::cout << "You lost " << m_enemie->getDamage() << "hp" << std::endl << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(550) );

    if( CCombat::win(m_player->getHealth(), m_enemie->getHealth()) ){
        std::cout << happines[(int)(rand() % happines.size())] << std::endl << "YOU ARE WINNER" <<  std::endl;
        std::cout << "Enter something to continue: " << std::endl;
        std::cin >> tmp;
        return true;
    }
    if( m_player->getHealth() <= 0){
        std::cout << defeat[(int)(rand() % defeat.size())] << std::endl << "CREATURE IS STILL ALIVE" <<  std::endl;
        std::cout << "Enter something to continue: " << std::endl;
        std::cin >> tmp;
    }
    else {
        std::cout << middle[(int)(rand() % middle.size())] << std::endl << "CREATURE IS STILL ALIVE" <<  std::endl;
        std::cout << "Enter something to continue: " << std::endl;
        std::cin >> tmp;
    }
    return false;
}

bool CCombat::win (const int& p_health, const int& e_health){
    if( p_health > 0 && e_health <= 0){
        return true;
    }
    
    return false;
}