#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int>& heap, int i) {
    int n = heap.size();
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && heap[l] < heap[smallest]) smallest = l;
    if(r < n && heap[r] < heap[smallest]) smallest = r;
    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertMinHeap(vector<int>& heap, int val) {
    heap.push_back(val);
    int i = heap.size() - 1;
    while(i != 0 && heap[(i-1)/2] > heap[i]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void printHeap(vector<int>& heap) {
    for(int x : heap) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> heap = {1, 3, 4, 5};
    insertMinHeap(heap, 2);
    printHeap(heap);
}
