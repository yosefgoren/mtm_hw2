#ifndef CHARACTER_H
#define CHARACTER_H
#include "iostream"
#include "Auxiliaries.h"

namespace mtm{
    class TileItem;
    class Character{
    public:
        Character(Team team, units_t health, units_t ammo, units_t range, units_t power);
        virtual Character* clone() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Character& character);
        virtual char getSymbol() const noexcept = 0;
        /**
         * checks if the character can move from src_point to dst_point in a single move.
         * ignores whether or not the character is really in src_point on the board.
         */
        bool canMoveThere(const GridPoint& src_point, const GridPoint& dst_point) const;
        virtual int maxMoveDistance() const noexcept = 0;
        /**
         * checks if the character can attack the dst_point from the src_point,
         * regardless of whether or not it is in src_point or what is in the tile of dst_point. 
         */
        virtual bool inAttackRange(const GridPoint& src_point, 
                const GridPoint& dst_point) const noexcept = 0;
        virtual bool canAttackTile(TileItem& other) const noexcept = 0;
        virtual void attackTile(const GridPoint& src_point,
                const GridPoint& dst_point, TileItem& target) = 0;

        const Team team;
        units_t health;
        units_t ammo;
        units_t range;
        units_t power;
    };
}

#endif