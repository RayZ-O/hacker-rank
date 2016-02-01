#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int prev = -1;
        int max_csum = -10000;
        int max_ncsum = -10000;
        for (int i = 0; i < n; i++) {
            if (max_ncsum < 0) {
                max_ncsum = max(max_ncsum, arr[i]);
            } else {
                max_ncsum += max(0, arr[i]);
            }
            if (prev < 0) {
                prev = arr[i];
            } else {
                prev += arr[i];
            }
            max_csum = max(max_csum, prev);
        }
        cout << max_csum << " " << max_ncsum << endl;
        t--;
    }
    return 0;
}
