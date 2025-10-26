#include <iostream>
#include <cmath>
using namespace std;
#define SIZE 50

class Stack {
    int arr[SIZE];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    void push(int v) { arr[++topIndex] = v; }
    int pop() { return arr[topIndex--]; }
    int top() { return arr[topIndex]; }
    bool empty() { return topIndex == -1; }
};

int main() {
    string exp = "23*54*+9-";
    Stack st;
    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.pop();
            int a = st.pop();
            switch(c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': st.push(pow(a, b)); break;
            }
        }
    }
    cout << st.top();
}
