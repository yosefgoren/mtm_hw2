#include "Soldier.h"

namespace mtm{
    Soldier::Soldier(Team team, units_t health, units_t ammo, units_t range, units_t power):
            Character(team, health, ammo, range, power){}
    char Soldier::getSymbol() const noexcept{
        return team == POWERLIFTERS ? 'S' : 's';
    }
    Character* Soldier::clone() const{
        return new Soldier(team, health, ammo, range, power);
    }
    int Soldier::maxMoveDistance() const noexcept{
        return 3;
    }
    bool Soldier::inAttackRange(const GridPoint& src_point, 
            const GridPoint& dst_point) const noexcept{
        //"can only attak in a straight line and no further than range"
        if(src_point.col == dst_point.col || src_point.row == dst_point.row){
            return GridPoint::distance(src_point, dst_point) <= range;
        }
        return false;
    }
    bool Soldier::canAttackTile(TileItem& other) const noexcept{
        return true;
    }
}