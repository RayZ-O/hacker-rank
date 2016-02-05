#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int, greater<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp.emplace(v[i], i);
    }
    auto it = mp.begin();
    int i = 0;
    while (k > 0 && it != mp.end()) {
        if (it->second != i) {
            int val = v[i];
            swap(v[i], v[it->second]);
            swap(mp[val], it->second);
            --k;
        }
        ++i;
        ++it;
    }
    for (int i : v) {
        cout << i << " ";
    }
    return 0;
}
