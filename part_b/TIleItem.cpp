#include "TileItem.h"

using namespace mtm;

namespace mtm{
    std::ostream& operator<<(std::ostream& os, const TileItem& item){
        os << (item.character ? 'c' : ' ');
        return os;
    }

    TileItem& TileItem::setCharacter(std::shared_ptr<Character> new_character){
        character = new_character;
        return *this;
    }
    TileItem& TileItem::operator=(const TileItem& other){
        character = other.character;
        return *this;
    }
}
