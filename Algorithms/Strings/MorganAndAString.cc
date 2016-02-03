#include <iostream>
using namespace std;


bool compare(string &s, int b1, string &t, int b2) {
    if (b1 == s.size()) return false;
    if (b2 == t.size()) return true;
    int i = b1, j = b2;
    while (i < s.size() && j < t.size()) {
        if (s[i] < t[j]) {
            return true;
        } else if (s[i] > t[j]) {
            return false;
        }
        i++;
        j++;
    }
    if (i == s.size() && j == t.size()) {
        return true;
    } else if (i == s.size()) {
        while (j + 1 < t.size() && t[j] == s[b1]) j++;
        return s[b1] < t[j];
    } else if (j == t.size()) {
        while (i + 1 < s.size() && s[i] == t[b2]) i++;
        return s[i] < t[b2];
    } else {
        return s[i] < t[j];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        string a, b;
        cin >> a >> b;
        int n = a.size() + b.size();
        int i = 0, j = 0;
        string res;
        while (i + j < n) {
            if (compare(a, i, b, j)) {
                char c = a[i++];
                res += c;
                while (i < a.size() && a[i] == c) {
                    res += a[i++];
                }
            } else {
                char c = b[j++];
                res += c;
                while (j < b.size() && b[j] == c) {
                    res += b[j++];
                }
            }
        }
        cout << res << endl;
        t--;
    }
    return 0;
}
