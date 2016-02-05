#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define NONE 0
#define LEFT 1
#define TOP 2
#define LEFTTOP 3

void printLCS(vector<vector<int>> &res, vector<int> &A, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (res[i][j] == LEFTTOP) {
        printLCS(res, A, i - 1, j - 1);
        cout << A[i-1] << " ";
    } else if (res[i][j] == LEFT) {
        printLCS(res, A, i, j - 1);
    } else {
        printLCS(res, A, i - 1, j);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<int>> res(n+1, vector<int>(m+1, NONE));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=m; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                res[i][j] = LEFTTOP;
            } else {
                if (dp[i][j-1] > dp[i-1][j]) {
                    dp[i][j] = dp[i][j-1];
                    res[i][j] = LEFT;
                } else {
                    dp[i][j] = dp[i-1][j];
                    res[i][j] = TOP;
                }
            }
        }
    }
    if  (dp[n][m] > 0) {
        printLCS(res, A, n, m);
    }
    return 0;
}
