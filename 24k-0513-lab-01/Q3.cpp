#include<iostream>
using namespace std;

class Exam {
    int* marks;
public:
    Exam(int m) {
        marks = new int(m);
    }

    ~Exam() { delete marks; }

    void set(int v) { *marks = v; }
    void show() { cout << *marks << endl; }
};

int main() {
    Exam e1(60);
    Exam e2 = e1;   // shallow copy (default copy constructor)

    e2.set(95);

    e1.show();
    e2.show();
}
