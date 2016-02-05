#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int t, d;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        cin >> t >> d;
        v.emplace_back(t+d, i);
    }
    sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
        return p1.first < p2.first || p1.first == p2.first && p1.second < p2.second;});
    for (auto p : v) {
        cout << p.second <<  " ";
    }
    return 0;
}
