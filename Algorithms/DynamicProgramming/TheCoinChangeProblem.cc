#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    vector<int> coins(m);
    for (int i = 0; i < m; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<vector<long>> dp(m + 1, vector<long>(n+1, 0L));
    for (int i = 1; i <= m; i++) {
        dp[i][0] = 1L;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j] + (j < coins[i-1] ? 0 : dp[i][j-coins[i-1]]);
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}
