#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int count = 0;
    int w = -5;
    for (int i = 0; i < n; i++) {
        if (v[i] > w + 4) {
            w = v[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
