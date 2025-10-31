#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high, int pivotIndex) {
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int method) {
    if (low < high) {
        int pivotIndex;
        switch (method) {
            case 1: pivotIndex = low; break;
            case 2: pivotIndex = low + rand() % (high - low + 1); break;
            case 3: pivotIndex = (low + high) / 2; break;
            case 4: {
                int mid = (low + high) / 2;
                int a = arr[low], b = arr[mid], c = arr[high];
                if ((a <= b && b <= c) || (c <= b && b <= a)) pivotIndex = mid;
                else if ((b <= a && a <= c) || (c <= a && a <= b)) pivotIndex = low;
                else pivotIndex = high;
                break;
            }
            default: pivotIndex = high;
        }
        int pi = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pi - 1, method);
        quickSort(arr, pi + 1, high, method);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int method = 1; method <= 4; method++) {
        int temp[100];
        for (int i = 0; i < n; i++) temp[i] = arr[i];
        comparisons = 0;
        quickSort(temp, 0, n - 1, method);
        cout << "\nMethod " << method << " - ";
        if (method == 1) cout << "First element pivot:\n";
        if (method == 2) cout << "Random element pivot:\n";
        if (method == 3) cout << "Middle element pivot:\n";
        if (method == 4) cout << "Median of three pivot:\n";
        cout << "Sorted array: ";
        printArray(temp, n);
        cout << "Comparisons: " << comparisons << endl;
    }
    return 0;
}
