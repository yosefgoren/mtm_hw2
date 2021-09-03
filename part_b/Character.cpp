#include "Character.h"

namespace mtm
{
    Character::Character(Team team, units_t health, units_t ammo, units_t range, units_t power):
            team(team), health(health), ammo(ammo), range(range), power(power){}       
    std::ostream& operator<<(std::ostream& os, const Character& character){
        os << character.getSymbol();
        return os;
    }
    bool Character::canMoveThere(const GridPoint& src_point, const GridPoint& dst_point) const{
        return GridPoint::distance(src_point, dst_point) <= maxMoveDistance();
    }
}