#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> st;
        unordered_map<char, char> mp{{')', '('}, {']', '['}, {'}', '{'}};
        for (char c: s) {
            if (st.empty() || mp.find(c) == mp.end()) {
                st.push(c);
            } else if (mp[c] == st.top()) {
                st.pop();
            } else {
                break;
            }
        }
        cout << (st.empty() ? "YES" : "NO") << endl;
    }
    return 0;
}
