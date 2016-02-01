#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int p, q;
    cin >> p >> q;
    bool found = false;
    for (int i = p; i <= q; i++) {
        int d = countDigits(i);
        long square = static_cast<long>(i) * i;
        int factor = pow(10, d);
        int l = square / factor;
        int r = square - l * factor;
        if (l + r == i) {
            found = true;
            cout << i << " ";
        }
    }
    if (!found) {
        cout << "INVALID RANGE" << endl;
    }
    return 0;
}
