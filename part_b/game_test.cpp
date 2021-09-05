#include "Game.h"

using namespace std;
using namespace mtm;

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
    auto sniper = Game::makeCharacter(SNIPER, POWERLIFTERS, 1, 1, 2, 1);
    auto soldier = Game::makeCharacter(SOLDIER, CROSSFITTERS, 1, 1, 2, 1);
    g.addCharacter(GridPoint(0,2), medic);
    g.addCharacter(GridPoint(0,1), sniper);
    g.addCharacter(GridPoint(1,1), soldier);
    cout << g << endl;
    g.attack(GridPoint(0,2), GridPoint(0,1));
    g.attack(GridPoint(0,1), GridPoint(1,1));
}

int main(){
    cout << "starting game test\n";

    testCopy();
    testAttack();

    cout << "finished game test\n";
}