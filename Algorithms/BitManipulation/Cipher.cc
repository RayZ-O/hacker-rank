#include <string>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string res(n, '0');
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int b = (s[i] - '0') ^ cur;
        res[i] = b  + '0';
        if (i < k - 1) {
            cur ^= b;
        } else {
            cur ^= (res[i-k+1] - '0') ^ b;
        }
    }
    cout << res << endl;
    return 0;
}
