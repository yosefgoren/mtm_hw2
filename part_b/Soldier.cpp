#include "Soldier.h"
#include <assert.h>
#include <math.h>

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
        return ceil((double)numerator / (double)denominator);
    }

    bool Soldier::targetIsLegal(const GridPoint& attacking_position, const TileItem& tile) const{
        return attacking_position.row == tile.getLocation().row 
                || attacking_position.col == tile.getLocation().col;
    }

    vector<GridPoint> Soldier::coordinatesAffectedByAttack(const GridPoint& src_point
            , TileItem& target) const{
        const GridPoint& target_point = target.getLocation();
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
    void Soldier::executeAttack(std::vector<TileItem*> targeted_tiles,
            const GridPoint& target_point) noexcept{
        unsigned int partial_damage = roundUp(power, 2);
        for(TileItem* tile : targeted_tiles){
            assert(!tile);
            assert(!tile->tileEmpty());
            Character& targeted_character = *(tile->getCharacter());
        
            if(targeted_character.team != team){
                targeted_character.health -= (tile->getLocation() == target_point ? power : partial_damage);
                tile->cleanIfDead();
            }             
        }
        ammo--;
    }
    void Soldier::reload() noexcept{
        ammo += 3;
    }
}