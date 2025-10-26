#include <iostream>
using namespace std;
#define SIZE 10

struct Node {
    string url;
    Node* next;
    Node(string u) : url(u), next(NULL) {}
};

class Stack {
    string arr[SIZE];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    void push(string s) { arr[++topIndex] = s; }
    void pop() { if (topIndex >= 0) topIndex--; }
    bool empty() { return topIndex == -1; }
};

void visit(Node*& head, Stack& s, string url) {
    Node* n = new Node(url);
    n->next = head;
    head = n;
    s.push(url);
}

void back(Node*& head, Stack& s, int times) {
    for (int i = 0; i < times; i++) {
        if (!s.empty()) s.pop();
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

void display(Node* head) {
    Node* t = head;
    while (t) { cout << t->url << " "; t = t->next; }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Stack s;
    visit(head, s, "Google");
    visit(head, s, "Facebook");
    visit(head, s, "Twitter");
    visit(head, s, "LinkedIn");
    visit(head, s, "Instagram");
    back(head, s, 2);
    display(head);
}
