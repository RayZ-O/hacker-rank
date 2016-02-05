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
        vector<int> A(n);
        vector<int> B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());
        int i;
        for (i = 0; i < n; i++) {
            if (A[i] + B[i] < k) {
                break;
            }
        }
        cout << (i == n ? "YES" : "NO") << endl;
    }

    return 0;
}
