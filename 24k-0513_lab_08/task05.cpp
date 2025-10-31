#include <iostream>
using namespace std;

struct Node {
    int id, qty;
    Node *left, *right;
    Node(int i, int q) {
        id = i;
        qty = q;
        left = right = NULL;
    }
};

Node* insert(Node* r, int id, int qty) {
    if (!r) return new Node(id, qty);
    if (id == r->id)
        r->qty = qty;
    else if (id < r->id)
        r->left = insert(r->left, id, qty);
    else
        r->right = insert(r->right, id, qty);
    return r;
}

Node* search(Node* r, int id) {
    if (!r || r->id == id) return r;
    return (id < r->id) ? search(r->left, id) : search(r->right, id);
}

void maxQty(Node* r, Node*& maxNode) {
    if (!r) return;
    if (!maxNode || r->qty > maxNode->qty) maxNode = r;
    maxQty(r->left, maxNode);
    maxQty(r->right, maxNode);
}

int main() {
    Node* root = NULL;
    int n, id, qty;
    cout << "How many products: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter ID and Quantity: ";
        cin >> id >> qty;
        root = insert(root, id, qty);
    }
    cout << "Enter ID to search: ";
    cin >> id;
    Node* s = search(root, id);
    if (s)
        cout << "Product " << id << " found with qty " << s->qty << endl;
    else
        cout << "Not found" << endl;
    Node* m = NULL;
    maxQty(root, m);
    if (m)
        cout << "Product with max quantity: " << m->id << " (" << m->qty << ")";
}
