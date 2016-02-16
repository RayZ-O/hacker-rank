#include <cmath>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        int count = 0;
        while (n > 1 && n & (n-1)) {
            n -= 1ULL << static_cast<int>(log2(n));
            count++;
        }
        cout << ((count + static_cast<int>(log2(n))) % 2 ? "Louise" : "Richard") << endl;
    }

    return 0;
}
