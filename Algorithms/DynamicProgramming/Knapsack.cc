#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> dp(k+1, 0);
        for (int i = 1; i <= k; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (v[j] <= i) {
                    dp[i] = max(dp[i], v[j] + dp[i-v[j]]);
                }
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}
