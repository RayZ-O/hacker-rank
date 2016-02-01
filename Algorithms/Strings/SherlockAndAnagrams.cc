#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        string s;
        cin >> s;
        int n = s.size();
        int count = 0;
        unordered_map<string, int> mp;
        for (int len = 1; len < n; len++) {
            for (int i = 0; i <= n - len; i++) {
                string r = s.substr(i, len);
                sort(r.begin(), r.end());
                if (mp.find(r) != mp.end()) {
                    count += mp[r];
                }
                mp[r]++;
            }
        }
        cout << count << endl;
        t--;
    }
    return 0;
}
