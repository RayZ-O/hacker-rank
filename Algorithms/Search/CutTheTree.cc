#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Vertex {
public:
    int val;
    int sum;
    bool visited;
    vector<int> adj_list;
    Vertex(int v) : val(v), visited(false) {}
};

int dfs(vector<Vertex> &graph, int i, int total, int &min_cut) {
    graph[i].visited = true;
    int sum = 0;
    for (int j : graph[i].adj_list) {
        if (!graph[j].visited) {
            sum += dfs(graph, j, total, min_cut);
        }
    }
    sum += graph[i].val;
    graph[i].sum = sum;
    int remain = total - sum;
    min_cut = min(min_cut, abs(remain - sum));
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<Vertex> graph{Vertex(-1)};
    int val;
    int total;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        total += val;
        graph.emplace_back(val);
    }
    int a, b;
    while (cin >> a >> b) {
        graph[a].adj_list.push_back(b);
        graph[b].adj_list.push_back(a);
    }
    int min_cut = total;
    for (int i = 1; i <= n; i++) {
        if (graph[i].adj_list.size() == 1) {
            dfs(graph, i, total, min_cut);
            cout << min_cut << endl;
            break;
        }
    }
    return 0;
}
