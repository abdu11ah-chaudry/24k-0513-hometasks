#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int time;
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int  n2 = right - mid;
    Runner L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) 
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) 
    {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}


void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


int main() {
    Runner runners[10] = {
        {"Ali", 4700}, {"Ahmed", 3450}, {"chow", 4000},
        {"Shakir", 3550}, {"Emaan", 3420}, {"Babar", 3900},
        {"Nagori", 3700}, {"Basheer", 2300}, {"Inaam", 4100},
        {"Jabeen", 3250}
    };

    mergeSort(runners, 0, 9);

    cout << "Top 5 fastest runners:\n";
    for (int i = 0; i < 5; i++){
        cout <<"Runner "<<i+1<<" name: "<< runners[i].name <<endl << "Finish Time (in seconds): " << runners[i].time << " seconds\n";
    }
    return 0;

}
