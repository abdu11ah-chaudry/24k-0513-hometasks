#include <iostream>
using namespace std;
#define SIZE 5

struct Order {
    string item;
    int quantity;
};

class Queue {
    Order arr[SIZE];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    bool full() { return rear == SIZE - 1; }
    bool empty() { return front == -1; }

    void enqueue(string item, int qty) {
        if (full()) {
            cout << "Overflow - No more orders can be added\n";
            return;
        }
        if (empty()) front = 0;
        arr[++rear] = {item, qty};
        cout << "Order added: " << item << " x" << qty << endl;
    }

    void dequeue() {
        if (empty()) {
            cout << "Underflow - No orders to process\n";
            return;
        }
        cout << "Processing order: " << arr[front].item << " x" << arr[front].quantity << endl;
        if (front == rear) front = rear = -1;
        else front++;
    }

    void display() {
        if (empty()) {
            cout << "No pending orders\n";
            return;
        }
        cout << "Pending Orders:\n";
        for (int i = front; i <= rear; i++)
            cout << arr[i].item << " x" << arr[i].quantity << endl;
    }
};

int main() {
    Queue q;
    q.enqueue("Burger", 2);
    q.enqueue("Pizza", 1);
    q.enqueue("Fries", 3);
    q.display();
    q.dequeue();
    q.display();
}
