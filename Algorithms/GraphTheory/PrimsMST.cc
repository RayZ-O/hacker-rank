#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Vertex {
public:
    bool finish;
    int key;
    vector<pair<int, int>> adj_list;
    Vertex() : finish(false), key(-1) {}
};

int extractMin(vector<Vertex> &graph) {
    int min_key = 10e5;
    int min_idx = -1;
    for (int i = 1; i < graph.size(); i++) {
        if (!graph[i].finish && graph[i].key != -1 && graph[i].key < min_key)  {
            min_key = graph[i].key;
            min_idx = i;
        }
    }
    return min_idx;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    vector<Vertex> graph(n+1);
    for (int i = 0; i < m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        graph[x].adj_list.emplace_back(y, r);
        graph[y].adj_list.emplace_back(x, r);
    }
    int s;
    cin >> s;
    graph[s].key = 0;
    int i = s;
    int tot_weight = 0;
    do {
        graph[i].finish = true;
        tot_weight += graph[i].key;
        for (auto p : graph[i].adj_list) {
            if (graph[p.first].key == -1 || p.second < graph[p.first].key) {
                graph[p.first].key = p.second;
            }
        }
        i = extractMin(graph);
    } while (i > 0);
    cout << tot_weight << endl;
    return 0;
}
