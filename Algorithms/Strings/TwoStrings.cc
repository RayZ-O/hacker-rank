#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        string s, r;
        cin >> s >> r;
        int dict[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            dict[s[i]-'a']++;
        }
        bool flag = false;
        for (int i = 0; i < r.size(); i++) {
            if (dict[r[i]-'a']) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
        t--;
    }
    return 0;
}
