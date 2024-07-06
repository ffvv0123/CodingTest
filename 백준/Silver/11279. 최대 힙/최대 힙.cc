#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;
    
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }
    

    void heapifyUp(int index) {
        while (index != 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) largest = left;
        if (right < heap.size() && heap[right] > heap[largest]) largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.size() == 0) {
            return 0;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return root;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
    int N, x;
    cin >> N;

    MaxHeap maxheap;

    for(int i = 0; i < N; i++) {
        cin >> x;

        if (x > 0) {
            maxheap.insert(x);
        }
        else {
            cout << maxheap.extractMax() << '\n';
        }
    }

    return 0;
}