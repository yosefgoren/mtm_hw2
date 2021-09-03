#include "Medic.h"
#include "TileItem.h"

namespace mtm{
    Medic::Medic(Team team, units_t health, units_t ammo, units_t range, units_t power):
            Character(team, health, ammo, range, power){}
    char Medic::getSymbol() const noexcept{
        return team == POWERLIFTERS ? 'M' : 'm';
    }
    Character* Medic::clone() const{
        return new Medic(team, health, ammo, range, power);
    }
    int Medic::maxMoveDistance() const noexcept{
        return 5;
    }
    bool Medic::inAttackRange(const GridPoint& src_point,
            const GridPoint& dst_point) const noexcept{
        return GridPoint::distance(src_point, dst_point) <= range;
    }
    bool Medic::canAttackTile(TileItem& other) const noexcept{
        return !other.tileEmpty();
    }
}