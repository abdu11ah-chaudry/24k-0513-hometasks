#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

struct Pair {
    Node* first;
    Node* second;
};

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Pair partition(Node* head) {
    if (!head) return {nullptr, nullptr};
    Node* pivot = head;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* leftTail = nullptr;
    Node* rightTail = nullptr;
    Node* curr = head->next;
    while (curr) {
        Node* next = curr->next;
        if (curr->data < pivot->data) {
            if (!left) {
                left = curr;
                leftTail = curr;
            } else {
                leftTail->next = curr;
                leftTail = curr;
            }
        } else {
            if (!right) {
                right = curr;
                rightTail = curr;
            } else {
                rightTail->next = curr;
                rightTail = curr;
            }
        }
        curr->next = nullptr;
        curr = next;
    }
    if (leftTail) leftTail->next = nullptr;
    if (rightTail) rightTail->next = nullptr;
    return {left, right};
}

Node* quickSort(Node* head) {
    if (!head || !head->next) return head;
    Pair p = partition(head);
    Node* left = p.first;
    Node* right = p.second;
    left = quickSort(left);
    right = quickSort(right);
    Node* result = left;
    if (left) {
        Node* tail = left;
        while (tail->next) tail = tail->next;
        tail->next = head;
    } else {
        result = head;
    }
    head->next = right;
    return result;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(7);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(3);
    head = quickSort(head);
    printList(head);
    return 0;
}
