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
    vector<int> len_min(1, 0);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(len_min.begin(), len_min.end(), v[i]);
        if (it == len_min.end()) {
            len_min.push_back(v[i]);
        } else {
            *it = min(*it, v[i]);
        }
    }
    cout << len_min.size() - 1 << endl;
    return 0;
}
