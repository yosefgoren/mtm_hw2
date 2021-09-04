#ifndef TILE_ITEM_H
#define TILE_ITEM_H

#include <memory>
#include <iostream>
#include "Character.h"
#include "Auxiliaries.h"

namespace mtm{    
    class TileItem{
    public:
        TileItem(): character(nullptr), current_location(0,0){}
        friend std::ostream& operator<<(std::ostream& os, const TileItem& item);
        TileItem& setCharacter(std::shared_ptr<Character> new_character);
        std::shared_ptr<Character> getCharacter() noexcept;
        const GridPoint& getLocation() const noexcept;
        TileItem& setLocation(const GridPoint& new_location) noexcept;
        //std::shared_ptr<Character const> getCharacter() const noexcept;
        TileItem& operator=(const TileItem& other);
        bool tileEmpty() const noexcept;
        
    private:
        std::shared_ptr<Character> character;
        GridPoint current_location;
    };
}

#endif
