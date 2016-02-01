#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Vertex {
    bool visited;
    int dist;
    vector<int> adj_list;
    Vertex() : visited(false), dist(-1) {}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t) {
        int n, m, s;
        cin >> n >> m;
        vector<Vertex> graph(n+1);
        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            graph[x].adj_list.push_back(y);
            graph[y].adj_list.push_back(x);
        }
        cin >> s;
        graph[s].visited = true;
        graph[s].dist = 0;
        queue<int> q;
        q.push(s);
        int d = 6;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (int i : graph[n].adj_list) {
                if (!graph[i].visited) {
                    q.push(i);
                    graph[i].visited = true;
                    graph[i].dist = graph[n].dist + 6;
                }
            }
        }
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
