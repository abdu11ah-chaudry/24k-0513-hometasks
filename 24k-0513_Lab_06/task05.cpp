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
    string exp = "-+2*345";
    Stack st;
    for (int i = exp.size() - 1; i >= 0; i--) {
        char c = exp[i];
        if (isdigit(c)) st.push(c - '0');
        else {
            int op1 = st.pop();
            int op2 = st.pop();
            int res = 0;
            switch(c) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '^': res = pow(op1, op2); break;
            }
            st.push(res);
        }
    }
    cout << st.top();
}
