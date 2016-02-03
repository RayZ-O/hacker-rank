#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

class Vertex {
public:
    int dist;
    bool finish;
    vector<pair<int, int>> adj_list;
    Vertex() : dist(-1), finish(false) {}
};

int extractMin(vector<Vertex> &graph) {
    int min_idx = -1;
    int min_dist = INT_MAX;
    for (int i = 1; i < graph.size(); i++) {
        if (!graph[i].finish && graph[i].dist != -1 && graph[i].dist < min_dist) {
            min_idx = i;
            min_dist = graph[i].dist;
        }
    }
    return min_idx;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        int n, m;
        cin >> n >> m;
        int x, y, r;
        vector<Vertex> graph(n+1);
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> r;
            graph[x].adj_list.emplace_back(y, r);
            graph[y].adj_list.emplace_back(x, r);
        }
        int s;
        cin >> s;
        graph[s].dist = 0;
        int i = s;
        do {
            graph[i].finish = true;
            for (auto u : graph[i].adj_list) {
                if (graph[u.first].dist == -1 || graph[u.first].dist > graph[i].dist + u.second) {
                    graph[u.first].dist = graph[i].dist + u.second;
                }
            }
            i = extractMin(graph);
        } while(i > 0);
        for (int i = 1; i <= n; i++) {
            if (i != s) {
                cout << graph[i].dist << " ";
            }
        }
        cout << endl;
        t--;
    }
    return 0;
}
