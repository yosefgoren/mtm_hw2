#include "Game.h"
#include "Exceptions.h"
#include "Character.h"
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
        return Character::createCharacter(type, team, health, ammo, range, power);
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

    void Game::attack(const GridPoint& src_coordinates , const GridPoint& dst_coordinates){
        if(!positionWithinBoard(src_coordinates) || !positionWithinBoard(dst_coordinates)){
            throw IllegalCell();
        }
        TileItem& attacking_tile = (*this)(src_coordinates);
        if(attacking_tile.tileEmpty()){
            throw CellEmpty();
        }
        Character& attacker = *attacking_tile.getCharacter();
        TileItem& target_tile = (*this)(dst_coordinates);
        if(!attacker.inAttackRange(src_coordinates, target_tile)){
            throw OutOfRange();
        }
        if(!attacker.hasAmmoToAttack(target_tile)){
            throw OutOfAmmo();
        }
        if(!attacker.targetIsLegal(src_coordinates, target_tile)){
            throw IllegalTarget();
        }

        vector<GridPoint> affected_coordiantes = 
                attacker.coordinatesAffectedByAttack(src_coordinates, target_tile);
        vector<TileItem*> affected_tiles;
        for(const GridPoint& coordinate : affected_coordiantes){
            if(positionWithinBoard(coordinate) && !((&(*this)(coordinate))->tileEmpty()) ){
                affected_tiles.push_back(&(*this)(coordinate));
            }
        }
        attacker.executeAttack(affected_tiles, dst_coordinates);
    }

    void Game::reload(const GridPoint& coordinates){
        if(!positionWithinBoard(coordinates)){
            throw IllegalCell();
        }
        TileItem& tile = (*this)(coordinates);
        if(tile.tileEmpty()){
            throw CellEmpty();
        }
        tile.getCharacter()->reload();
    }

    bool Game::isOver(Team* winningTeam) const{
        int powerlifter_count = 0, crossfitter_count = 0;
        for(const TileItem& item : *this){
            if(!item.tileEmpty()){
                (item.getTeam() == CROSSFITTERS ? crossfitter_count : powerlifter_count)++;
            }
        }
        if(powerlifter_count == 0 && crossfitter_count == 0){
            return false;
        }
        if(powerlifter_count == 0 || crossfitter_count == 0){
            if(winningTeam != nullptr){
                *winningTeam = (powerlifter_count > crossfitter_count ? POWERLIFTERS : CROSSFITTERS);
            }
            return true;
        }
        return false;
    }
}
