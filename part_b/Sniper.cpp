#include "Sniper.h"
#include "TileItem.h"

using namespace std;

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
    vector<GridPoint> Sniper::coordinatesAffectedByAttack(const GridPoint& src_point,
                TileItem& target) const{
        int distance = GridPoint::distance(src_point, target.getLocation());
        if(distance > range || distance < range/2){
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
}