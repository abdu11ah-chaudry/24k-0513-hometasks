#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    double price;
    string description;
    bool availability;
};

int partition(Product products[], int low, int high) {
    double pivot = products[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (products[j].price < pivot) {
            i++;
            swap(products[i], products[j]);
        }
    }
    swap(products[i + 1], products[high]);
    return i + 1;
}

void quickSort(Product products[], int low, int high) {
    if (low < high) {
        int pi = partition(products, low, high);
        quickSort(products, low, pi - 1);
        quickSort(products, pi + 1, high);
    }
}

int main() {
    Product products[3];
    cout<<"Enter details of 3 products: "<<endl;
    for (int i = 0; i < 3; i++) {
        cout << "Enter product " << i + 1 << " name: ";
        getline(cin, products[i].name);
        cout << "Enter price: ";
        cin >> products[i].price;
        cin.ignore();
        cout << "Enter description: ";
        getline(cin, products[i].description);
        cout << "Available (1 for yes, 0 for no): ";
        cin >> products[i].availability;
        cin.ignore();
    }

    quickSort(products, 0, 2);

    cout << "\nProducts sorted by price:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << products[i].name << "\nPrice: " << products[i].price
             << "\nDescription: " << products[i].description
             << "\nAvailable: " << (products[i].availability ? "Yes" : "No") << "\n\n";
    }
    return 0;
}
