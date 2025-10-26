#include <iostream>
using namespace std;
#define SIZE 5

class Queue {
    string arr[SIZE];
    int front, rear;
public:
    Queue() { front = rear = -1; }
    bool empty() { return front == -1; }
    bool full() { return rear == SIZE - 1; }
    void enqueue(string name) {
        if (full()) return;
        if (empty()) front = 0;
        arr[++rear] = name;
    }
    void dequeue() {
        if (empty()) return;
        if (front == rear) front = rear = -1;
        else front++;
    }
    void display() {
        if (empty()) cout << "No patrons\n";
        else for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue("Ali");
    q.enqueue("Bilal");
    q.enqueue("Sara");
    q.display();
    q.dequeue();
    q.display();
}
