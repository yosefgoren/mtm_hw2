#include <iostream>

using namespace std;

template <const char* str>
class OneStringPony{
public:
    static void foo(){
        cout << str << endl;
    }
};

int main(int, char**) {
    std::cout << "Hello, world!\n";
    OneStringPony<"olaaa">::foo();
}
