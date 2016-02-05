#include <cmath>
#include <iostream>
using namespace std;

int maxXor(int l, int r) {
    int n = ceil(log2(l ^ r));
    return pow(2, n) - 1;
}

int main() {
    int res;
    int _l;
    cin >> _l;

    int _r;
    cin >> _r;

    res = maxXor(_l, _r);
    cout << res;

    return 0;
}
