#include "TileItem.h"

using namespace mtm;

namespace mtm{
    std::ostream& operator<<(std::ostream& os, const TileItem& item){
        os << item.character;
        return os;
    }
}
