#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) : name(n), score(s), next(NULL) {}
};

void insert(Node*& head, string name, int score) {
    Node* newNode = new Node(name, score);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    while (head) {
        cout << head->name << " : " << head->score << endl;
        head = head->next;
    }
}

int getMax(Node* head) {
    int maxVal = head->score;
    while (head) {
        if (head->score > maxVal)
            maxVal = head->score;
        head = head->next;
    }
    return maxVal;
}

int getDigit(int num, int exp) {
    return (num / exp) % 10;
}

Node* countingSort(Node* head, int exp) {
    Node* buckets[10] = {NULL};
    Node* tails[10] = {NULL};

    // Distribute nodes into buckets
    Node* curr = head;
    while (curr) {
        int digit = getDigit(curr->score, exp);
        Node* nextNode = curr->next;
        curr->next = NULL;

        if (!buckets[digit]) {
            buckets[digit] = tails[digit] = curr;
        } else {
            tails[digit]->next = curr;
            tails[digit] = curr;
        }
        curr = nextNode;
    }

    // Combine all buckets
    Node* newHead = NULL;
    Node* tail = NULL;
    for (int i = 0; i < 10; ++i) {
        if (buckets[i]) {
            if (!newHead) {
                newHead = buckets[i];
                tail = tails[i];
            } else {
                tail->next = buckets[i];
                tail = tails[i];
            }
        }
    }
    return newHead;
}

void radixSort(Node*& head) {
    int maxVal = getMax(head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        head = countingSort(head, exp);
    }
}

int main() {
    Node* head = NULL;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cout << "Enter name and score: ";
        cin >> name >> score;
        insert(head, name, score);
    }

    cout << "\nOriginal List:\n";
    display(head);

    radixSort(head);

    cout << "\nSorted List (Ascending by Score):\n";
    display(head);

    return 0;
}
