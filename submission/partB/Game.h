#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "TileItem.h"

namespace mtm{
    class Game : public Board<TileItem>{
    public:
        Game(int height, int width);
        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team, 
                units_t health, units_t ammo, units_t range, units_t power);
        void move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void attack(const GridPoint& src_coordinates , const GridPoint& dst_coordinates);
        void reload(const GridPoint& coordinates);
        bool isOver(Team* winningTeam = NULL) const;
    };
}

#endif