#ifndef CHARACTER_H
#define CHARACTER_H
#include "iostream"
#include "Auxiliaries.h"
#include "TileItem.h"
#include "Exceptions.h"
#include <vector>

namespace mtm{
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
    
        /*
         * @return the set of coordinates that might be 
         * involved if the character will attack the 'target' tile from src_point.
         * some of the coordinates returned might be out of the board and should be ignored.
         * @throw the following exceptions might be thrown in this order:
         *      OutOfRange -  cannot attack due to it's position.
         *      OutOfAmmo - cannot attack due to a lack of ammo.
         *      IllegalTarget - cannot attack due to the content of 'target'.
         */
        virtual std::vector<GridPoint> coordinatesAffectedByAttack(const GridPoint& src_point,
                TileItem& target) const = 0;

        /**
         * @param targeted_tiles - expected to be the tiles of the coordinates 
         * given by 'coordiantesAffectedByAttack'.
         * @param target_point - the point targeted by the attack.
         * the method will affect the targeted tiles as needed and the character itself 
         * for example: possibly reduce the health of the characters within the tiles
         * and reduce the ammo of the attacker (this).
         */
        virtual void executeAttack(std::vector<TileItem*> targeted_tiles,
                const GridPoint& target_point) noexcept = 0;

        virtual void reload() noexcept = 0;
        bool shouldBeDead() const noexcept;

        static std::shared_ptr<Character> createCharacter(CharacterType type, Team team, 
            units_t health, units_t ammo, units_t   range, units_t power);

        const Team team;
        units_t health;
        units_t ammo;
        units_t range;
        units_t power;
    };
}

#endif