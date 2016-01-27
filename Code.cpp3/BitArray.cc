#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, s, p, q;
    cin >> n >> s >> p >> q;
    int m = 0x7fffffff;
    vector<bool> b(m, false);
    int last = s & m;
    b[last] = true;
    int count = 1;
    for (int i = 1; i < n; i++) {
        int cur = (static_cast<long>(last) * p + q) & m;
        if (b[cur]) {
            break;
        }
        count++;
        b[cur] = true;
        last = cur;
    }
    cout << count << endl;
    return 0;
}
