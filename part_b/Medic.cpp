#include "Medic.h"
#include "TileItem.h"

using namespace std;

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

    vector<GridPoint> Medic::coordinatesAffectedByAttack(const GridPoint& src_point,
                TileItem& target) const{
        if(GridPoint::distance(src_point, target.getLocation()) > range){
            throw OutOfRange();
        }
        //if medic has no ammo and the target is an empty tile, should we throw OutOfAmmo or IllegalTarget?
        if(target.tileEmpty()){
            throw IllegalTarget();
        }
        if(target.getCharacter()->team != team && ammo == 0){
            throw OutOfAmmo();
        }
        vector<GridPoint> result;
        result.push_back(target.getLocation());
        return result;
    }
}