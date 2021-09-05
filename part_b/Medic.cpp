#include "Medic.h"
#include "TileItem.h"
#include "assert.h"

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
        if(target.tileEmpty() || src_point == target.getLocation()){
            throw IllegalTarget();
        }
        if(target.getCharacter()->team != team && ammo == 0){
            throw OutOfAmmo();
        }
        vector<GridPoint> result;
        result.push_back(target.getLocation());
        return result;
    }
    void Medic::executeAttack(std::vector<TileItem*> targeted_tiles, const GridPoint& target_point) noexcept{
        assert(targeted_tiles.size() == 1);
        TileItem& targeted_tile = *(targeted_tiles.back());
        assert(!targeted_tile.tileEmpty());
        assert(targeted_tile.getLocation() == target_point);
        if(targeted_tile.getCharacter()->team == team){
            targeted_tile.getCharacter()->health += power;
        } else {
            targeted_tile.getCharacter()->health -= power;
            targeted_tile.cleanIfDead();
            ammo--;
        }
    }
    void Medic::reload() noexcept{
        ammo += 5;
    }
}