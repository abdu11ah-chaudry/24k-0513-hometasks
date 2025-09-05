#include<iostream>
using namespace std;

class Box {
    int* volume;
public:
    Box() {
        volume = new int(0);
    }

    Box(int v) {
        volume = new int(v);
    }

    Box(const Box& b) {
        volume = new int(*b.volume);
    }

    Box& operator=(const Box& b) {
        if(this != &b) {
            delete volume;
            volume = new int(*b.volume);
        }
        return *this;
    }

    ~Box() { delete volume; }

    void set(int v) { *volume = v; }
    void show() { cout << *volume << endl; }
};

int main() {
    Box b1(10);
    b1.show();

    Box b2 = b1;
    b2.set(25);

    b1.show();
    b2.show();
}
