#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class MoreCookTime {
public:
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    long cur = 0;
    long total = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MoreCookTime> pq;
    int i = 0;
    while (i < n || !pq.empty()) {
        while (pq.empty() || i < n && v[i].first == pq.top().first) {
            pq.emplace(v[i].first, v[i].second);
            i++;
        }
        while (i < n && v[i].first <= cur) {
            pq.emplace(v[i].first, v[i].second);
            i++;
        }
        auto p = pq.top();
        pq.pop();
        cur = max(cur, static_cast<long>(p.first)) + p.second;
        total += cur - p.first;
    }
    cout << total / n << endl;
    return 0;
}
