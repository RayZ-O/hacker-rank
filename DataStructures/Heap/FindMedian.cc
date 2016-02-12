#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    while (n--) {
        int val;
        cin >> val;
        if (max_heap.empty()) {
            max_heap.push(val);
        } else if (max_heap.size() == min_heap.size()) {
            if (val < max_heap.top()) {
                max_heap.push(val);
            } else {
                min_heap.push(val);
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        } else {
            max_heap.push(val);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        if (max_heap.size() > min_heap.size())  {
            cout << fixed << setprecision(1) << static_cast<double>(max_heap.top()) << endl;
        } else {
            cout << fixed << setprecision(1) << (max_heap.top() + min_heap.top()) / 2.0 << endl;
        }
    }
    return 0;
}
