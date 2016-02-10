#include <vector>
#include <iostream>
using namespace std;

class DisjointSet {
    int parent[64];
    int rank[64];
public:
    DisjointSet() {
        for (int i = 0; i < 64; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    void merge(vector<int> &t) {
        if (t.size() < 2) {
            return;
        }
        for (int i = 1; i < t.size(); i++) {
            union_set(t[0], t[i]);
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
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
            parent[y] = x;
        }

    }

    int components() const {
        int c = 0;
        for (int i = 0; i < 64; i++) {
            if (i == parent[i]) {
                c += 1;
            }
        }
        return c;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<unsigned long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> vt(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++) {
            if ((v[i] >> j) & 1) {
                vt[i].push_back(j);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < pow(2, n); i++) {
        DisjointSet dset;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                dset.merge(vt[j]);
            }
        }
        count += dset.components();
    }
    cout << count << endl;
    return 0;
}
