#include "Sniper.h"
#include "TileItem.h"
#include <assert.h>
#include <math.h>

using namespace std;

namespace mtm{
    Sniper::Sniper(Team team, units_t health, units_t ammo, units_t range, units_t power):
            Character(team, health, ammo, range, power), num_successfull_attacks(0){}
    char Sniper::getSymbol() const noexcept{
        return team == POWERLIFTERS ? 'N' : 'n';
    }
    Character* Sniper::clone() const{
        return new Sniper(team, health, ammo, range, power);
    }
    int Sniper::maxMoveDistance() const noexcept{
        return 4;
    }
    vector<GridPoint> Sniper::coordinatesAffectedByAttack(const GridPoint& src_point,
                TileItem& target) const{
        int distance = GridPoint::distance(src_point, target.getLocation());
        if(distance > range || distance < ceil((double)range / 2.0)){
            throw OutOfRange();
        }
        if(ammo == 0){
            throw OutOfAmmo();
        }
        if(target.tileEmpty() || target.getCharacter()->team == team){
            throw IllegalTarget();
        }
        vector<GridPoint> result;
        result.push_back(target.getLocation());
        return result;
    }
    void Sniper::executeAttack(std::vector<TileItem*> targeted_tiles, const GridPoint& target_point) noexcept{
        assert(targeted_tiles.size() == 1);
        TileItem& targeted_tile = *(targeted_tiles.back());
        assert(!targeted_tile.tileEmpty());
        assert(targeted_tile.getCharacter()->team != team);
        assert(targeted_tile.getLocation() == target_point);
        num_successfull_attacks++;
        ammo--;
        int damage_dealt = power*(1 + (num_successfull_attacks%3 == 0));
        targeted_tile.getCharacter()->health -= damage_dealt;
    }
}