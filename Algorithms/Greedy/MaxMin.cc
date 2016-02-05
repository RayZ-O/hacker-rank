#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    vector<int> v(N);
    for (int i=0; i<N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i + K - 1 < N; i++) {
        unfairness = min(unfairness, v[i+K-1] - v[i]);
    }

    cout << unfairness << "\n";
    return 0;
}
