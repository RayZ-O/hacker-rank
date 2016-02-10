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
    stack<int> st;
    int area = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[i] < v[st.top()]) {
            int h = v[st.top()];
            st.pop();
            area = max(area, h * (st.empty() ? i : i - st.top() - 1));
        }
        st.push(i);
    }
    while (!st.empty()) {
        int h = v[st.top()];
        st.pop();
        area = max(area, h * (st.empty() ? n : n - st.top() - 1));
    }
    cout << area << endl;
    return 0;
}
