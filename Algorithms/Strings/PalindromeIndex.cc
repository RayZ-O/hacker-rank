#include <iostream>
using namespace std;

int isPalindrome(string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return l;
        }
        l++;
        r--;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        string s;
        cin >> s;
        int i = isPalindrome(s, 0, s.size() - 1);
        int r = s.size() - 1 - i;
        if (i != -1 && isPalindrome(s, i+1, r) != -1) {
            i = r;
        }
        cout << i << endl;
        t--;
    }
    return 0;
}
