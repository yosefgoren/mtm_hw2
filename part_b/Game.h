#ifndef GAME_H
#define GAME_H
#include "Auxiliaries.h"
#include "Exceptions.h"
#include "Character.h"
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"
#include <memory>

namespace mtm{
    class Game{
    public:
        Game(int height, int width);
        ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team, 
                units_t health, units_t ammo, units_t range, units_t power);
        void move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void attack(const GridPoint& src_coordinates , const GridPoint& dst_coordinates);
        void reload(const GridPoint& coordinates);
        std::ostream& operator<<(std::ostream& os) const;
        bool isOver(Team* winningTeam = NULL) const;
    private:
        shared_ptr<Character> characterAt(const GridPoint& coordinates);

        shared_ptr<Character> character_board;
    };

}

#endif