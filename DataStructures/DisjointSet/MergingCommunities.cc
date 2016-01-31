#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class DisjointSets {
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
public:
    void add_set() {
        parent.push_back(-1);
        size.push_back(1);
        rank.push_back(0);
    }

    void union_set(int x, int y) {
        link(find_set(x), find_set(y));
    }

    void link(int x, int y) {
        if (x == y) {
            return;
        }
        if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int find_set(int x) {
        while (parent[x] != -1) {
            x = parent[x];
        }
        return x;
    }

    int get_size(int x) {
        return size[find_set(x)];
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    DisjointSets dset;
    for (int i = 0; i < n; i++) {
        dset.add_set();
    }
    char op;
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> op >> a;
        if (op == 'M') {
            cin >> b;
            dset.union_set(a - 1, b - 1);
        } else {
            cout << dset.get_size(a - 1) << endl;
        }
    }
    return 0;
}
