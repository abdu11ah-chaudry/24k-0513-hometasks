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

int subtreeSum(Node* r, int target, bool &found) {
    if (!r) return 0;
    int s = r->data + subtreeSum(r->left, target, found) + subtreeSum(r->right, target, found);
    if (s == target) found = true;
    return s;
}

int main() {
    Node* root = build();
    int target;
    cout << "Enter target sum: ";
    cin >> target;
    bool found = false;
    subtreeSum(root, target, found);
    if (found)
        cout << "Subtree with sum " << target << " exists.";
    else
        cout << "No such subtree found.";
}
