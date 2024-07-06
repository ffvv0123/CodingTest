#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
public:
    vector<int> heap;
    
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }
    

    void heapifyUp(int index) {
        while (index != 0 && heap[parent(index)] > heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
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

    MinHeap minheap;

    for(int i = 0; i < N; i++) {
        cin >> x;

        if (x > 0) {
            minheap.insert(x);
        }
        else {
            cout << minheap.extractMin() << '\n';
        }
    }

    return 0;
}