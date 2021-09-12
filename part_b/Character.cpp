#include "Character.h"
#include "Soldier.h"
#include "Sniper.h"
#include "Medic.h"

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
    bool Character::shouldBeDead() const noexcept{
        return health <= 0;
    }
    std::shared_ptr<Character> Character::createCharacter(CharacterType type, Team team, 
            units_t health, units_t ammo, units_t   range, units_t power){
        switch(type){
            case SOLDIER:
            return std::make_shared<Soldier>(Soldier(team, health, ammo, range, power));
            case MEDIC:
            return std::make_shared<Medic>(Medic(team, health, ammo, range, power));
            case SNIPER:
            return std::make_shared<Sniper>(Sniper(team, health, ammo, range, power));
        }
        return nullptr;
    }
}