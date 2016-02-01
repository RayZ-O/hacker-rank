#include <iostream>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    int count[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
    }
    map<int, int> mp;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            mp[count[i]]++;
            if (mp.size() > 2) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if (mp.size() == 1) {
        cout << "YES" << endl;
    } else {
        auto p1 = mp.begin();
        auto p2 = ++mp.begin();
        if (p2->first - p1->first == 1 && p2->second == 1
           || p1->first == 1 && p1->second == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
