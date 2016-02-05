#include <cmath>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    long l, r;
    while (t--) {
        cin >> l >> r;
        long h = log2(l & r);
        long res = 0;
        while (h && (l >> h & 1) == (r >> h & 1)) {
            res += (l >> h & 1) << h;
            h--;
        }
        if (!h && (l & 1) == (r & 1)) {
            res += l & 1;
        }
        cout << res << endl;
    }
    return 0;
}
