#include <iostream>
#include <memory>

using namespace std;

class LinearArena{
    public:
        unique_ptr<byte[]> buffer;
        size_t capasity;
        size_t offset = 0;
};


int main(){
    cout << "hello" << endl;


    return 0;
}