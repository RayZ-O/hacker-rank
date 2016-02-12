#include <climits>
#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (q--) {
        int d;
        cin >> d;
        deque<int> dq;
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && v[i] > v[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i - dq.front() >= d) {
                dq.pop_front();
            }
            if (i >= d - 1) {
                res = min(res, v[dq.front()]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
