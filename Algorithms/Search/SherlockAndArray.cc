#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if (n == 1) {
            cout << "YES" << endl;
        } else {
            int left = 0;
            int right = accumulate(v.begin()+1, v.end(), 0);
            bool found = false;
            for (int i = 1; i < n - 1; i++) {
                left += v[i-1];
                right -= v[i];
                if (left == right) {
                    found = true;
                    break;
                }
            }
            cout << (found ? "YES" : "NO") << endl;
        }
        t--;
    }
    return 0;
}
