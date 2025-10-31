#include <iostream>
using namespace std;

struct Node {
    int id;
    Node *left, *right;
    Node(int i) {
        id = i;
        left = right = NULL;
    }
};

Node* insert(Node* r, int id) {
    if (!r) return new Node(id);
    if (id < r->id)
        r->left = insert(r->left, id);
    else
        r->right = insert(r->right, id);
    return r;
}

Node* LCA(Node* r, int a, int b) {
    if (!r) return NULL;
    if (r->id > a && r->id > b) return LCA(r->left, a, b);
    if (r->id < a && r->id < b) return LCA(r->right, a, b);
    return r;
}

int main() {
    Node* root = NULL;
    int n, x;
    cout << "Enter number of employees: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter employee ID: ";
        cin >> x;
        root = insert(root, x);
    }
    int a, b;
    cout << "Enter two employee IDs: ";
    cin >> a >> b;
    Node* l = LCA(root, a, b);
    if (l)
        cout << "Closest common manager ID: " << l->id;
    else
        cout << "No common manager found.";
}
