#include <iostream>
using namespace std;
#define SIZE 50

class Stack {
    char arr[SIZE];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    void push(char c) { arr[++topIndex] = c; }
    char pop() { return arr[topIndex--]; }
    char top() { return arr[topIndex]; }
    bool empty() { return topIndex == -1; }
};

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i", res;
    Stack st;
    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];
        if (isalnum(c)) res += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') res += st.pop();
            st.pop();
        } else {
            while (!st.empty() && prec(st.top()) >= prec(c)) res += st.pop();
            st.push(c);
        }
    }
    while (!st.empty()) res += st.pop();
    cout << res;
}
