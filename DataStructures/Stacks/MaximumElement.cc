#include <stack>
#include <iostream>
using namespace std;

class MaxStack {
    stack<int> st;
    stack<int> mst;
public:
    void push(int x) {
        st.push(x);
        if (mst.empty() || x >= mst.top()) {
            mst.push(x);
        }
    }

    void pop() {
        if (st.top() == mst.top()) {
            mst.pop();
        }
        st.pop();
    }

    int max() {
        return mst.top();
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    MaxStack ms;
    while (n--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            ms.push(x);
        } else if (type == 2) {
            ms.pop();
        } else {
            cout << ms.max() << endl;
        }
    }
    return 0;
}
