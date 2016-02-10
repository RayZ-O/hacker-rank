#include <stack>
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
    int days = 0;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int d = 1;
        while (!st.empty() && v[i] <= st.top().first) {
            d = max(d, st.top().second + 1);
            st.pop();
        }
        if (!st.empty()) {
            days = max(days, d);
        }
        st.emplace(v[i], d);
    }
    cout << days << endl;
    return 0;
}
