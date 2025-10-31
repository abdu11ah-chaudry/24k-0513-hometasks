#include <iostream>
using namespace std;

struct Node {
    string name;
    Node *left, *right;
    Node(string n) {
        name = n;
        left = right = NULL;
    }
};

Node* create() {
    string x;
    cout << "Enter package name (or 'none'): ";
    cin >> x;
    if (x == "none") return NULL;
    Node* node = new Node(x);
    cout << "Enter left of " << x << endl;
    node->left = create();
    cout << "Enter right of " << x << endl;
    node->right = create();
    return node;
}

void display(Node* root, int space = 0) {
    if (!root) return;
    space += 5;
    display(root->right, space);
    for (int i = 5; i < space; i++) cout << " ";
    cout << root->name << endl;
    display(root->left, space);
}

int main() {
    Node* root = create();
    cout << "\nTour Package Hierarchy:\n";
    display(root);
}
