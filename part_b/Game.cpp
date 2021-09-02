#include "Game.h"
#include "Exceptions.h"
#include "Soldier.h"

using namespace mtm;
using namespace std;

Game::Game(int height, int width):Board<TileItem>(height, width, TileItem()){}

void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character){
    (*this)(coordinates).setCharacter(character);
}

static std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team, 
        units_t health, units_t ammo, units_t range, units_t power){
    make_shared<Soldier>();
    
}
// void Game::move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
// void Game::attack(const GridPoint& src_coordinates , const GridPoint& dst_coordinates);
// void Game::reload(const GridPoint& coordinates);
// std::ostream& Game::operator<<(std::ostream& os) const;
// bool Game::isOver(Team* winningTeam = NULL) const;
