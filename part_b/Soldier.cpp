#include "Soldier.h"

using namespace std;

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

    static unsigned int roundUp(unsigned int numerator, unsigned int denominator){
        if(numerator%denominator == 0){
            return numerator/denominator;
        }
        return numerator/denominator + 1;
    }

    vector<GridPoint> Soldier::coordinatesAffectedByAttack(const GridPoint& src_point, TileItem& target) const{
        const GridPoint& target_point = target.getLocation();
        if(!(src_point.row == target_point.row || src_point.col == target_point.col)
                ||  GridPoint::distance(src_point, target_point) <= range){
            throw OutOfRange();
        }
        if(ammo == 0){
            throw OutOfAmmo();
        }
        vector<GridPoint> result = vector<GridPoint>();
        int splash_distance = roundUp(range, 3);
        for(int dy = -splash_distance; dy <= splash_distance; ++dy){
            for(int dx = -splash_distance; dx <= splash_distance; ++dx){
                GridPoint point(target_point.row + dy, target_point.col + dx);
                if(GridPoint::distance(point, target_point) <= splash_distance){
                    result.push_back(point);
                }
            }
        }
        return result;
    }
}