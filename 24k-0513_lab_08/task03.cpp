#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* build() {
    int x;
    cout << "Enter value (-1 for none): ";
    cin >> x;
    if (x == -1) return NULL;
    Node* n = new Node(x);
    cout << "Enter left of " << x << endl;
    n->left = build();
    cout << "Enter right of " << x << endl;
    n->right = build();
    return n;
}

bool isFull(Node* r) {
    if (!r) return true;
    if ((r->left == NULL) != (r->right == NULL)) return false;
    return isFull(r->left) && isFull(r->right);
}

int main() {
    Node* root = build();
    if (isFull(root))
        cout << "Tree is Full Binary Tree";
    else
        cout << "Tree is NOT Full Binary Tree";
}
