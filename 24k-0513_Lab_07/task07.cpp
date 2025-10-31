#include <iostream>
#include <cstdlib>
#include <ctime>
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
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    srand(time(0));
    int n = 50;
    int scores[50];

    for (int i = 0; i < n; i++)
        scores[i] = rand() % 101;

    cout << "Original Scores:\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << endl;

    radixSort(scores, n);

    cout << "\nSorted Scores (Ascending):\n";
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << endl;

    cout << "\nRanks:\n";
    for (int i = 0; i < n; i++)
        cout << "Student " << i + 1 << " Rank: " << n - i << " (Score: " << scores[i] << ")\n";

    return 0;
}
