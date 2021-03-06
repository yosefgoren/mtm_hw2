#include "Game.h"
#include "Character.h"
#include "Auxiliaries.h"

using namespace std;
using namespace mtm;

void printStats(Character* c){
    cout << *c << " | "; 
    cout << "health=" << c->health << " | ";
    cout << "ammo=" << c->ammo << endl;
}

void testCopy(){
    Game g1(2, 2);
    g1.addCharacter(GridPoint(0,0), Game::makeCharacter(SOLDIER, POWERLIFTERS, 10, 10, 10, 10));
    cout << g1 << endl;
    Game g2(g1);
    g2.move(GridPoint(0,0), GridPoint(1,1));
    cout << g2 << endl;
    cout << g1 << endl;
}

void testAttack(){
    Game g(2,3);
    auto medic = Game::makeCharacter(MEDIC, POWERLIFTERS, 1, 1, 2, 1);
    printStats(medic.get());
    auto sniper = Game::makeCharacter(SNIPER, POWERLIFTERS, 1, 1, 2, 1);
    auto soldier = Game::makeCharacter(SOLDIER, CROSSFITTERS, 1, 1, 2, 1);
    cout << g.isOver() << endl;
    g.addCharacter(GridPoint(0,2), medic);
    g.addCharacter(GridPoint(0,1), sniper);
    g.addCharacter(GridPoint(1,1), soldier);
    cout << g << endl;
    g.attack(GridPoint(0,2), GridPoint(0,1));
    cout << g.isOver() << endl;
    g.attack(GridPoint(0,1), GridPoint(1,1));
    g.reload(GridPoint(0,1));
    cout << g << endl;
    cout << g.isOver() << endl;
}

int main(){
    cout << "starting game test\n";

    testCopy();
    testAttack();

    cout << "finished game test\n";
}