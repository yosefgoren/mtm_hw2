#include "Sniper.h"
#include "TileItem.h"

namespace mtm{
    Sniper::Sniper(Team team, units_t health, units_t ammo, units_t range, units_t power):
            Character(team, health, ammo, range, power){}
    char Sniper::getSymbol() const noexcept{
        return team == POWERLIFTERS ? 'N' : 'n';
    }
    Character* Sniper::clone() const{
        return new Sniper(team, health, ammo, range, power);
    }
    int Sniper::maxMoveDistance() const noexcept{
        return 4;
    }
    bool Sniper::inAttackRange(const GridPoint& src_point, const GridPoint& dst_point) const noexcept{
        int distance = GridPoint::distance(src_point, dst_point);
        return distance <= range && distance >= range/2;
    }
    bool Sniper::canAttackTile(TileItem& other) const noexcept{
        return !other.tileEmpty() && other.getCharacter()->team != team;
    }
}