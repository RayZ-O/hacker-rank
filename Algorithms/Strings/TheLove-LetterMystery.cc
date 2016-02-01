#include <cmath>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        string s;
        cin >> s;
        int cnt = 0;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            cnt += abs(s[l] - s[r]);
            l++;
            r--;
        }
        cout << cnt << endl;
        t--;
    }
    return 0;
}
