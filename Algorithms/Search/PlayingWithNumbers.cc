#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int k = -1;
    vector<long> sums{0};
    for (int i = 0; i < n; i++) {
        if (v[i] < 0) {
            k = i;
        }
        long sum = i > 0 ? sums.back() : 0;
        sums.push_back(sum + v[i]);
    }
    int pos = k + 1;
    int q;
    cin >> q;
    long offset = 0;
    while (q--) {
        int x;
        cin >> x;
        offset += x;
        int idx = distance(v.begin(), lower_bound(v.begin(), v.end(), -offset));
        long sum = 0;
        sum += sums[n] - sums[idx] + (n - idx) * offset;
        sum -= (sums[idx]) + idx * offset;
        cout << sum << endl;
    }
    return 0;
}
