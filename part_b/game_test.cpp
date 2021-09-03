#include "Game.h"

using namespace std;
using namespace mtm;

int main(){
    Game g(2, 4);
    cout << g << endl;
    Game g2(g);
    g2.addCharacter(GridPoint(0,0), Game::makeCharacter(SOLDIER, POWERLIFTERS, 10, 10, 10, 10));
    cout << g2 << endl;
    g.addCharacter(GridPoint(0,1), Game::makeCharacter(SOLDIER, CROSSFITTERS, 10, 10, 10, 10));
    cout << g << endl;
    g.move(GridPoint(0,1), GridPoint(1,1));
    cout << g << endl;
    g.addCharacter(GridPoint(0,0), Game::makeCharacter(SNIPER, POWERLIFTERS, 1, 1, 1, 1));
    g.addCharacter(GridPoint(0,1), Game::makeCharacter(MEDIC, CROSSFITTERS, 1, 1, 1, 1));
    cout << g << endl;
    cout << "finished game test\n";
}