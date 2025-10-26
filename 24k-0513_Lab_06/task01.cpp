#include <iostream>
using namespace std;
#define SIZE 5

struct Call {
    string name;
    string number;
    int duration;
};

class CallStack {
    Call arr[SIZE];
    int topIndex;
public:
    CallStack() { topIndex = -1; }
    bool empty() { return topIndex == -1; }
    void push(string n, string num, int d) {
        if (topIndex == SIZE - 1) return;
        arr[++topIndex] = {n, num, d};
    }
    void pop() {
        if (empty()) return;
        topIndex--;
    }
    void top() {
        if (empty()) return;
        cout << arr[topIndex].name << " " << arr[topIndex].number << " " << arr[topIndex].duration << endl;
    }
    void display() {
        if (empty()) cout << "No calls\n";
        else for (int i = topIndex; i >= 0; i--) cout << arr[i].name << " " << arr[i].number << " " << arr[i].duration << endl;
    }
};

int main() {
    CallStack s;
    s.push("Ali","123",5);
    s.push("Bilal","456",3);
    s.display();
    s.top();
    s.pop();
    s.display();
}
