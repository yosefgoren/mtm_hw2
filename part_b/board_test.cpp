#include "Board.h"

using namespace std;
using namespace mtm;

class A : public Board<int>{
    public:
    A(int value):Board<int>(5,5,value){}
    void foo(){
        cout << *this << endl;
    }
};

int main(){
    cout << "starting board test\n";
    A(3).foo();
    cout << "finished board test\n";
}