#include <vector>
#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX

class Heap {
    vector<int> heap_;
public:
    bool in_heap(int i) {
        return i < heap_.size();
    }

    int parent(int i) {
        return (i-1) / 2;
    }

    int left(int i) {
        return 2*i + 1;
    }

    int right(int i) {
        return 2*i + 2;
    }

    int min() {
        if (!heap_.empty()) {
            return heap_[0];
        } else {
            return INF;
        }
    }

    int extractMin() {
        return erase(min());
    }

    void insert(int v) {
        heap_.push_back(v);
        int pos = heap_.size() - 1;
        while (pos != 0 && heap_[pos] < heap_[parent(pos)]) {
            swap(heap_[pos], heap_[parent(pos)]);
            pos = parent(pos);
        }
    }

    int erase(int v) {
        int i;
        for (i = 0; i < heap_.size(); i++) {
            if (heap_[i] == v) {
                break;
            }
        }
        swap(heap_[i], heap_.back());
        heap_.pop_back();
        heapify(i);
        return v;
    }

    void heapify(int i) {
        if (!in_heap(i)) {
            return;
        }
        int l = left(i), r = right(i);
        if (!in_heap(l)) {
            return;
        }
        int pos = !in_heap(r) ? l : heap_[l] < heap_[r] ? l : r;
        if (heap_[pos] < heap_[i]) {
            swap(heap_[pos], heap_[i]);
            heapify(pos);
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
    Heap heap;
    while (q--) {
        int t, v;
        cin >> t;
        if (t == 1) {
            cin >> v;
            heap.insert(v);
        } else if (t == 2) {
            cin >> v;
            heap.erase(v);
        } else {
            cout << heap.min() << endl;
        }
    }
    return 0;
}
