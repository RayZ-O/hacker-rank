#include <stack>
#include <string>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack<pair<int, string>> history;
    string s;
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        if (t == 1) {
            string w;
            cin >> w;
            history.emplace(1, to_string(w.size()));
            s += w;
        } else if (t == 2) {
            int k;
            cin >> k;
            history.emplace(2, s.substr(s.size() - k, k));
            s.erase(s.end() - k, s.end());
        } else if (t == 3) {
            int k;
            cin >> k;
            cout << s[k-1] << endl;
        } else {
            auto h = history.top();
            history.pop();
            if (h.first == 1) {
                s.erase(s.end() - stoi(h.second), s.end());
            } else {
                s += h.second;
            }
        }
    }
    return 0;
}
