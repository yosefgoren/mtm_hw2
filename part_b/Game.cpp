#include "Game.h"
#include "Exceptions.h"
#include "Character.h"
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"
#include <vector>

using namespace std;
namespace mtm{
    Game::Game(int height, int width):Board<TileItem>(height, width, TileItem()){
        for(auto it = this->begin(); it != this->end(); ++it){
            (*it).setLocation(GridPoint(it));
        }
    }

    void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character){
        (*this)(coordinates).setCharacter(character);
    }

    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team, 
            units_t health, units_t ammo, units_t   range, units_t power){
        switch(type){
            case SOLDIER:
            return make_shared<Soldier>(Soldier(team, health, ammo, range, power));
            case MEDIC:
            return make_shared<Medic>(Medic(team, health, ammo, range, power));
            case SNIPER:
            return make_shared<Sniper>(Sniper(team, health, ammo, range, power));
        }
        return nullptr;
    }

    void Game::move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates){
        if(!positionWithinBoard(dst_coordinates) || !positionWithinBoard(src_coordinates)){
            throw IllegalCell();
        }
        TileItem& old_tile = (*this)(src_coordinates);
        if(old_tile.tileEmpty()){
            throw CellEmpty();
        }
        shared_ptr<Character> character = old_tile.getCharacter();
        if(!character->canMoveThere(src_coordinates, dst_coordinates)){
            throw MoveTooFar();
        }
        TileItem& new_tile = (*this)(dst_coordinates);
        if(!new_tile.tileEmpty()){
            throw CellOccupied();
        }
        old_tile.setCharacter(nullptr);
        new_tile.setCharacter(character);
    }

    // void Game::attack(const GridPoint& src_coordinates , const GridPoint& dst_coordinates){
    //     if(!positionWithinBoard(src_coordinates) || !positionWithinBoard(dst_coordinates)){
    //         throw IllegalCell();
    //     }
    //     TileItem& attacking_tile = (*this)(src_coordinates);
    //     if(attacking_tile.tileEmpty()){
    //         throw CellEmpty();
    //     }
    //     shared_ptr<Character> attacker = attacking_tile.getCharacter();
    //     if(!attacker->inAttackRange(src_coordinates, dst_coordinates)){
    //         throw OutOfRange();
    //     }
    //     if(!attacker.hasAmmoToAttack()){
    //         throw OutOfAmmo();
    //     }
    //     vector<const GridPoint&> affected_coordiantes = attacker.coordinatesAffectedByAttack(dst_coordinates);
    //     vector<TileItem&> affected_tiles;
    //     for(const GridPoint& coordinate : affected_coordiantes){
    //         affected_tiles.push_back((*this)(coordinate));
    //     }
    //     attacker.
    // }

    // void Game::reload(const GridPoint& coordinates);
    // std::ostream& Game::operator<<(std::ostream& os) const;
    // bool Game::isOver(Team* winningTeam = NULL) const;

}
