#include "inventory.hpp"

CBack_pack::CBack_pack( const int& n_size, const int& n_tmp ) : m_size(n_size), m_tmp_size(n_tmp), my_items ( std::vector<CItems*> ()) {}; 

CBack_pack::CBack_pack( const CBack_pack& other ) : m_size( other.m_size ), m_tmp_size ( other.m_tmp_size ), my_items( other.my_items ) {};

CBack_pack& CBack_pack::operator = ( CBack_pack other ){
    if( &other == this ){
        return *this;
    }

    m_size = other.m_size;
    m_tmp_size = other.m_tmp_size;

    CBack_pack::clearItems();

    for ( auto it = other.my_items.begin(); it != other.my_items.end(); it++ ){
        CBack_pack::addItem( *it );
    }
    return *this;
}

CBack_pack::~CBack_pack() {
    for( auto it = my_items.begin(); it != my_items.end(); it++){
        delete *it;
    }
}

CBack_pack& CBack_pack::addItem( CItems * obj ) {
    char tmp = 0;

    my_items.push_back( obj );
    m_tmp_size += obj->getSize();

    return *this;
}

CBack_pack& CBack_pack::delItem( const int & pos ){
    m_tmp_size += my_items[pos - 1]->getSize();

    delete my_items[pos - 1];
    my_items.erase(my_items.begin() + (pos - 1));

    return *this;
}

CBack_pack& CBack_pack::increaseSize(){
    m_size += 3;
    return *this;
}

CBack_pack& CBack_pack::clearItems (){
    for( auto it = my_items.begin(); it != my_items.end(); it++){
        delete *it;
    }

    my_items.clear();
    return *this;
}

CItems* CBack_pack::operator [] ( const int & pos ){
    return my_items[pos - 1];
}

std::ostream& CBack_pack::printInfoPlayer(std::ostream& os) {
    int pos_cnt = 1;

    if( my_items.empty() ){
        os << "Back pack is empty" << std::endl;
        return os;
    }

    os << "Capacity of the backpack / Free space in the backpacks: " << m_size << " / " << m_size - m_tmp_size << std::endl;
    for( const auto&  x  : my_items ){
        os << "#" << pos_cnt << " Name: " << x->getName() << std::endl;
        pos_cnt++;
    }

    return os;
}

std::ostream& CBack_pack::printInfoChest(std::ostream& os) {
    int pos_cnt = 1;

    if( my_items.empty() ){
        os << "Chest is empty" << std::endl;
        return os;
    }

    for( const auto&  x  : my_items ){
        os << "#" << pos_cnt << " Name: " << x->getName() << std::endl;
        pos_cnt++;
    }

    return os;
}

std::ostream& CBack_pack::getItemInfo ( std::ostream& os, const int & pos ){
    my_items[pos - 1]->printInfo( os );
    return os;
}

size_t CBack_pack::getSize () const{
    return my_items.size();
}

int CBack_pack::getOveralSize () const{
    return m_size;
}

int CBack_pack::getTmpSize () const{
    return m_tmp_size;
}

void CBack_pack::saveProgress ( std::ofstream& save_file ) {
    save_file << m_size << std::endl << my_items.size() << std::endl;

    for ( auto it = my_items.begin(); it != my_items.end(); it++ ){
        save_file << (*it)->getName() << std::endl << (*it)->getId() << std::endl << (*it)->getEquip() << std::endl << (*it)->getSize() << std::endl << (*it)->getParameter();
        if( it != my_items.end() - 1){
            save_file << std::endl;
        }
    }

 }