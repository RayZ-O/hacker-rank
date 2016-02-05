#include <vector>
#include <iostream>
using namespace std;

class Vertex {
public:
    bool visited;
    vector<int> adj_list;
    Vertex() : visited(false) {}
};

int dfs(vector<Vertex> &graph, int i, int &componet) {
    graph[i].visited = true;
    int count = 1;
    for (int v : graph[i].adj_list) {
        if (!graph[v].visited) {
            count += dfs(graph, v, componet);
        }
    }
    if (count % 2 == 0) {
        componet++;
        return 0;
    } else {
        return count;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    vector<Vertex> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].adj_list.push_back(b);
        graph[b].adj_list.push_back(a);
    }
    int componet = 0;
    dfs(graph, 1, componet);
    cout << componet - 1 << endl;
    return 0;
}
