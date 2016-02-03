#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        int m, n;
        cin >> m >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(m - v[i])) {
                cout << mp[m - v[i]] + 1 << " " << i + 1 << endl;
                break;
            } else {
                mp[v[i]] = i;
            }
        }
        t--;
    }
    return 0;
}
