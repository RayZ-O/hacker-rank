#include <cmath>
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
        string r = s;
        reverse(r.begin(), r.end());
        bool is_funny = true;
        for (int i = 1; i < s.size(); i++) {
            if (abs(s[i]-s[i-1]) != abs(r[i]-r[i-1])) {
                is_funny = false;
            }
        }
        cout << (is_funny ? "Funny" : "Not Funny") << endl;
        t--;
    }
    return 0;
}
