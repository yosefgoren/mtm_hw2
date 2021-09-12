#include "TileItem.h"
#include "Character.h"

using namespace mtm;

namespace mtm{
    std::ostream& operator<<(std::ostream& os, const TileItem& item){
        os << (item.character ? item.character->getSymbol() : ' ');
        return os;
    }
    TileItem& TileItem::setCharacter(std::shared_ptr<Character> new_character){
        character = new_character;
        return *this;
    }
    std::shared_ptr<Character> TileItem::getCharacter() noexcept{
        return character;
    }
    TileItem& TileItem::operator=(const TileItem& other){
        character = other.character;
        return *this;
    }
    bool TileItem::tileEmpty() const noexcept{
        return character == nullptr;
    }
    const GridPoint& TileItem::getLocation() const noexcept{
        return current_location;
    }
    TileItem& TileItem::setLocation(const GridPoint& new_location) noexcept{
        current_location = new_location;
        return *this;
    }
    void TileItem::cleanIfDead(){
        if(!tileEmpty() && character->shouldBeDead()){
            character = nullptr;
        }
    }
    Team TileItem::getTeam() const{
        if(character == nullptr){
            throw CellEmpty();
        }
        return character->team;
    }
}
