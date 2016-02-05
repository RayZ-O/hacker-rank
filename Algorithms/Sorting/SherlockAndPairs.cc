#include <vector>
#include <iostream>
#include <algorithm>
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
        sort(v.begin(), v.end());
        long count = 0, equal = 1;
        int beg = -1;
        v.push_back(-1);
        for (int i = 0; i <= n; i++) {
            if (beg == v[i]) {
                equal++;
            } else {
                beg = v[i];
                count += equal * (equal - 1);
                equal = 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}
