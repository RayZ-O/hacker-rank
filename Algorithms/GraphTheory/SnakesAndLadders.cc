#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Vertex {
public:
    bool visited;
    int dist;
    vector<int> adj_list;
    Vertex() : visited(false), dist(-1) {}
};

void changeEdge(vector<Vertex>& graph, int n) {
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        graph[a].adj_list.clear();
        graph[a].adj_list.push_back(b);
    }
}

int shortestPath(vector<Vertex>& graph, int src, int des) {
    queue<int> q;
    q.push(src);
    graph[src].visited = true;
    graph[src].dist = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        // handle ladders and snakes
        if (graph[v].adj_list.size() == 1) {
            int u = graph[v].adj_list[0];
            if (u == des) {
                return graph[v].dist;
            }
            if (graph[u].dist = -1) {
                graph[u].dist = graph[v].dist;
            }
            v = u;
        }
       // cout << "visiting: " << v  << "  dist: " << graph[v].dist<< "  adj: ";
        for (int u : graph[v].adj_list) {
          //  cout << u << " ";
            if (u == des) {
                return graph[v].dist + 1;
            } else if (!graph[u].visited) {
                graph[u].visited = true;
                graph[u].dist = graph[v].dist + 1;
                q.push(u);
            }
        }
      //  cout << endl;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, m;
    cin >> t;
    while (t--) {
        vector<Vertex> graph(101);
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 6; j++) {
                if (i + j <= 100) {
                    graph[i].adj_list.push_back(i + j);
                }
            }
        }
        cin >> n;
        changeEdge(graph, n);
        cin >> m;
        changeEdge(graph, m);
        cout << shortestPath(graph, 1, 100) << endl;
    }
    return 0;
}
