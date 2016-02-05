#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    unsigned int mask = 0;
    mask = ~mask;
    unsigned int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << (x ^ mask) << endl;
    }
    return 0;
}
