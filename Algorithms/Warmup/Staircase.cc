#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    cout.setf(ios::right);
    for (int i = 1; i <= n; i++) {
        cout.width(n);
        cout << string(i, '#') << endl;
    }
    return 0;
}
