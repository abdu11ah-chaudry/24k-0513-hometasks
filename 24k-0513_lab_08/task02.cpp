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

Node* insert() {
    int x;
    cout << "Enter value (-1 for none): ";
    cin >> x;
    if (x == -1) return NULL;
    Node* n = new Node(x);
    cout << "Enter left of " << x << endl;
    n->left = insert();
    cout << "Enter right of " << x << endl;
    n->right = insert();
    return n;
}

int countNodes(Node* r) {
    if (!r) return 0;
    return 1 + countNodes(r->left) + countNodes(r->right);
}

int countLeaves(Node* r) {
    if (!r) return 0;
    if (!r->left && !r->right) return 1;
    return countLeaves(r->left) + countLeaves(r->right);
}

int height(Node* r) {
    if (!r) return 0;
    int l = height(r->left);
    int ri = height(r->right);
    return 1 + max(l, ri);
}

int main() {
    Node* root = insert();
    cout << "Total Nodes: " << countNodes(root) << endl;
    cout << "Leaf Nodes: " << countLeaves(root) << endl;
    cout << "Height: " << height(root) << endl;
}
