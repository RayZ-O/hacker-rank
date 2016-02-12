#include <vector>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long end = n - 1;
        long cost = 0;
        long profit = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[end]) {
                cost += v[i];
            } else {
                profit += (end - i - 1) * v[end] - cost;
                end = i;
                cost = 0;
            }
        }
        if (end > 0) {
            profit += end * v[end] - cost;
        }
        cout << profit << endl;
    }
    return 0;
}
