#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int max_size;
public:
    DisjointSet(int n) : max_size(1) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            rank.push_back(0);
            size.push_back(1);
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_set(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) {
            return;
        }
        if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
            parent[x] = y;
            size[y] += size[x];
        }
        max_size = max(max_size, size[find(x)]);
    }

    int max_set() const {
        return max_size;
    }

    int min_set() const{
        int min_size = 30000;
        for (int i = 1; i < parent.size(); i++) {
            if (i == parent[i] && size[i] > 1) {
                min_size = min(min_size, size[i]);
            }
        }
        return min_size;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    DisjointSet dset(n*2);
    int g, b;
    while (n--) {
        cin >> g >> b;
        dset.union_set(g, b);
    }
    cout << dset.min_set() << " " << dset.max_set() << endl;
    return 0;
}
