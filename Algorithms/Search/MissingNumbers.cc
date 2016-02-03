#include <vector>
#include <iostream>
#include <map>
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
    int m;
    cin >> m;
    map<int, int> mp;
    int val;
    for (int i = 0; i < m; i++) {
        cin >> val;
        mp[val]++;
    }
    for (int i = 0; i < n; i++) {
        mp[v[i]]--;
    }
    for (auto p : mp) {
        if (p.second > 0) {
            cout << p.first << " ";
        }
    }
    return 0;
}
