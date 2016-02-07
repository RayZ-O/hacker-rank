#include <queue>
#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--) {
        long m, n;
        cin >> m >> n;
        priority_queue<int> cy, cx;
        int c;
        for (int i = 1; i < m; i++) {
            cin >> c;
            cy.push(c);
        }
        for (int i = 1; i < n; i++) {
            cin >> c;
            cx.push(c);
        }
        long cost = 0;
        while (!cy.empty() || !cx.empty()) {
            if (cx.empty()) {
                cost += cy.top() * (n - cx.size());
                cy.pop();
            } else if (cy.empty()) {
                cost += cx.top() * (m - cy.size());
                cx.pop();
            } else if (cy.top() > cx.top()) {
                cost += cy.top() * (n - cx.size());
                cy.pop();
            } else {
                cost += cx.top() * (m - cy.size());
                cx.pop();
            }
        }
        cout << cost % 1000000007 << endl;
    }
    return 0;
}
