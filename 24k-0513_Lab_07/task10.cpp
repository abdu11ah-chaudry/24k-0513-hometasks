#include <iostream>
#include <iomanip>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    int pass = 1;
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
        cout << "After pass " << pass++ << " (exp=" << exp << "): ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main() {
    int n = 20;
    int arr[20];
    cout << "Enter 20 Product IDs (5-digit integers):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nBefore Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << endl;

    radixSort(arr, n);

    cout << "\nAfter Sorting (Ascending):\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
