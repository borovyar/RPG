#include "items.hpp"
#include "../player.hpp"

CItems::CItems( const std::string & n_name, const int & n_size, const int & n_id, const int parameter, const bool n_equip ) : item_name ( n_name ), size ( n_size ), id ( n_id ),
                        unique_parameter ( parameter ), equip ( n_equip ) {};

CItems::~CItems() = default;

CItems::CItems ( const CItems & other ){
    this->item_name = other.item_name;
    this->size = other.size;
    this->id = other.id;
    this->unique_parameter = other.unique_parameter;
    this->used = other.used;
}

bool CItems::getUsed() const {
    return used;
}

bool CItems::getEquip() const{
    return equip;
}

int CItems::getId() const {
    return id;
}

int CItems::getSize() const {
    return size;
}

int CItems::getParameter() const{
    return unique_parameter;
}

std::string CItems::getName() const{
    return  item_name;
}
