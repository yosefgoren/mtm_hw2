#ifndef TILE_ITEM_H
#define TILE_ITEM_H

#include <memory>
#include <iostream>
#include "Character.h"

namespace mtm{    
    class TileItem{
    public:
        TileItem(): character(nullptr){}
        friend std::ostream& operator<<(std::ostream& os, const TileItem& item);
    private:
        std::shared_ptr<Character> character;
    };
}

#endif
