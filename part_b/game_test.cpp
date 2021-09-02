#include "Game.h"

using namespace std;
using namespace mtm;

int main(){
    Game g(2, 4);
    cout << g << endl;
    Game g2(g);
    g2.addCharacter(GridPoint(0,0), make_shared<Soldier>());
    cout << g2 << endl;
    cout << g << endl;
    cout << "finished game test\n";
}