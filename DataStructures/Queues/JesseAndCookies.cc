#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    int sw;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> sw;
        pq.push(sw);
    }
    int count = 0;
    while (!pq.empty() && pq.top() < k) {
        int sw1 = pq.top();
        pq.pop();
        if (pq.empty()) {
            break;
        }
        int sw2 = pq.top();
        pq.pop();
        pq.push(sw1 + 2 * sw2);
        count++;
    }
    cout << (pq.empty() ? -1 : count) << endl;
    return 0;
}
