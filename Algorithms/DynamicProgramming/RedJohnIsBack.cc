#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int countPrime(int n) {
    vector<bool> flag(n+1, true);
    int count = n - 1;
    for (int i = 2; i <= sqrt(n) + 1; i++) {
        if (flag[i]) {
            for (int j = i * i; j <= n; j += i) {
                if (flag[j]) {
                    flag[j] = false;
                    count--;
                }
            }
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> dp(n+1, 1);
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-4];
        }
        cout << countPrime(dp[n]) << endl;
    }
    return 0;
}
