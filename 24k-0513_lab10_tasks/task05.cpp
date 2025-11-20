#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& heap, int i) {
    int n = heap.size();
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && heap[l] > heap[largest]) largest = l;
    if(r < n && heap[r] > heap[largest]) largest = r;
    if(largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, largest);
    }
}

void insertMaxHeap(vector<int>& heap, int val) {
    heap.push_back(val);
    int i = heap.size() - 1;
    while(i != 0 && heap[(i-1)/2] < heap[i]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void removeMaxHeap(vector<int>& heap) {
    if(heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    maxHeapify(heap, 0);
}

void printHeap(vector<int>& heap) {
    for(int x : heap) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> heap = {1800, 1600, 1500, 1200};
    insertMaxHeap(heap, 1700);
    printHeap(heap);
    removeMaxHeap(heap);
    printHeap(heap);
}
