#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> v;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> res;
    int diff = 2 * 10e7;
    for (int i = 1; i < n; i++) {
        int d = v[i] - v[i-1];
        if (d < diff) {
            res = {{v[i-1], v[i]}};
            diff = d;
        } else if (d == diff) {
            res.emplace_back(v[i-1], v[i]);
        }
    }
    for (auto p : res) {
        cout << p.first << " " << p.second << " ";
    }
    return 0;
}
