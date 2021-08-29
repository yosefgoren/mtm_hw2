#include "Board.h"

using namespace std;
using namespace mtm;

int main(){
    cout << "starting board test\n";
    Board<int> board(3, 3, 2);
    cout << board << endl;
    for(auto& item : board)
        item++;
    cout << board << endl;
    board(0,0) = 6;
    cout << board << endl;
    cout << "finished board test\n";
}