#include "chest.hpp"
#include "player.hpp"

CChest::CChest( const int& n_x, const int& n_y, CBack_pack* n_items, std::set<std::string>& n_answers, const std::string & n_mystery, bool n_opened ) : m_x ( n_x ), m_y (n_y), items( n_items ), answers ( n_answers ),
                    mystery(n_mystery), opened( n_opened ){};

CChest::~CChest(){
    items->clearItems();
    delete items;
}

CChest& CChest::clearChest ( ){
    items->clearItems();
    return *this;
}

bool CChest::getOpened () const{
    return opened;
}

bool CChest::Empty() const{
    if( items->getSize() == 0 )
        return true;
    return false; 
}

int CChest::getX() const{
    return m_x;
}

int CChest::getY() const{
    return m_y;
}

CChest& CChest::openBackPack ( CPlayer* obj ){
    char tmp = 0;

    while ( 1 ){
        system("clear");

        items->printInfoChest( std::cout );

        std::cout << "Choose item ( enter number ) : ( Q to exit )" << std::endl;
        std::cin >> tmp;
        tmp = std::tolower ( tmp );

        if( tmp == 'q')
            break;
        else if ( tmp - '0' <= 0 || (size_t)(tmp - '0') > items->getSize()){
            system("clear");
            char out_of_range;
            std::cout << "Out of the range" << std::endl << "Enter something to continue:" << std::endl;
            std::cin >> out_of_range;
        }
        else{
            char tmp2 = 0;

            while( 1 ){
                system("clear");

                items->getItemInfo( std::cout, ( tmp - '0') );

                std::cout << "E ( add item ): ( Q to exit )" << std::endl;
                std::cin >> tmp2;
                tmp2 = std::tolower ( tmp2 );

                if( tmp2 == 'q' ){
                    break;
                }
                if( tmp2 == 'e'){
                    if( (*items)[ ( tmp - '0' ) ]->getSize() + obj->getCurrentBackPack() > obj->getSizeBackPack()){
                        system("clear");

                        char not_enough_space = 0;
                        std::cout << "Not enough space: " << std::endl << "Enter something to continue: " << std::endl;
                        std::cin >> not_enough_space;

                        break;
                    }

                    obj->addItem( (*items)[ tmp - '0']->clone() );
                    items->delItem( tmp - '0' );

                    break;
                }
            }

        }
    }

    opened = true;

    return *this;
}

CChest& CChest::openChest( CPlayer * obj ){
    std::string tmp;

    if ( !opened ){

        while( 1 ){
            system("clear");

            std::cout << mystery << std::endl;
            std::cout << "Try to answer : ( Q ( exit )" << std::endl;
            std::getline( std::cin >> std::ws , tmp);

            if( answers.count(tmp) == 1 ){
                CChest::openBackPack ( obj );
            }

            if ( tmp == "q" || tmp == "Q" ){
                break;
            }

            if( opened ){
                break;
            }

        }

        return *this;
    }

    CChest::openBackPack ( obj );

    return *this;;
}

void CChest::getInfo ( std::ostream& os ){
    system("clear");

    char tmp;
    os << "THIS CHEST CONTAINS " << items->getSize() << " ITEMS " << std::endl << "TRY TO OPEN IT " << std::endl << "Enter something to continue" << std::endl;
    std::cin >> tmp;
}

void CChest::saveChest ( std::ofstream& save_file ){
    save_file << m_x << std::endl << m_y << std::endl;
    save_file << opened << std::endl;
    save_file << mystery << std::endl;
    save_file << (int)answers.size() << std::endl;

    for( const auto & it : answers ){
        save_file << it << std::endl;
    }

    items->saveProgress( save_file );
}