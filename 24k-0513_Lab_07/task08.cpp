#include <iostream>
#include <string>

using namespace std;

struct Order {
    int orderID;
    string customerName;
    double totalPrice;
};

int partition(Order arr[], int low, int high) {
    double pivot = arr[high].totalPrice;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].totalPrice <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Order arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Order orders[5] = {
        {101, "Babar", 250.50},
        {102, "Ali", 150.75},
        {103, "Chaman", 300.00},
        {104, "Jabbar", 200.25},
        {105, "Nasir", 175.00}
    };
    quickSort(orders, 0, 4);
    cout << "Sorted orders by total price (ascending):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "OrderID: " << orders[i].orderID << ", Customer: " << orders[i].customerName << ", Price: " << orders[i].totalPrice << endl;
    }
    return 0;
}
