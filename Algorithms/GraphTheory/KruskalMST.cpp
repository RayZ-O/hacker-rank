#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;
public:
    void makeSets(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findSet(int x) {
        if (parent[x] != x) {
            parent[x] = findSet(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        x = findSet(x);
        y = findSet(y);
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
};

class Edge {
public:
    int x;
    int y;
    int r;
    Edge(int u, int v, int w) : x(u), y(v), r(w) {}
    bool operator < (const Edge &rhs) const {
        return r < rhs.r;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    DisjointSet ds;
    ds.makeSets(n);
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        edges.emplace_back(x, y, r);
    }
    sort(edges.begin(), edges.end());
    int tot_weight = 0;
    for (auto e : edges) {

        if (ds.findSet(e.x) != ds.findSet(e.y)) {
            tot_weight += e.r;
            ds.unionSet(e.x, e.y);
        }
    }
    cout << tot_weight << endl;
    return 0;
}
