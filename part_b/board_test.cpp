#include "Board.h"

using namespace std;
using namespace mtm;

    class A{
        public:
        A* foo(){
        A* a = this;
        return a; 
        }
    };

int main(){
    cout << "starting board test\n";
    cout << A().foo() << endl;
    cout << "finished board test\n";
}