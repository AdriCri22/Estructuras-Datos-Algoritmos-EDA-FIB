#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <vector>
using namespace std;

// pair<cost, node>
typedef pair<int, int> Adj;
typedef vector<Adj> Col;
typedef vector<Col> Graph;


Adj dijkstra(const Graph& graph, int src, int des) {
  // Array of visited vertices
  vector<bool> vis(graph.size(), false);
  // Array of distance between the source and other nodes
  vector<int> dist(graph.size(), INT_MAX);
  dist[src] = 0;    // Set the source node as distance 0
  // Array of ways to go to some node from sorce node
  vector<int> ways(graph.size(), 0);
  ways[src] = 1;
  // Creates a queue ordered by distance increasingly pair<dist, node>
  priority_queue<Adj, vector<Adj>, greater<Adj>> q;
  q.push({0, src});   // Add the source node to queue

  while (not q.empty()) {
    Adj adj = q.top();
    q.pop();

    int u = adj.second;
    if (not vis[u]) {
      vis[u] = true;

      for (auto adj2 : graph[u]) {
        int v = adj2.second;
        int w = adj2.first;
        if (dist[v] > dist[u] + w) {
          ways[v] = ways[u];
          dist[v] = dist[u] + w;
          q.push({dist[v], v});
        }
        // The statement omits (not like the previous one) that only exists a unique path
        else if (dist[v] == dist[u] + w)
          ways[v] += ways[u];

      }

    }
  }

  return {dist[des], ways[des]};
}

void print_graph(const Graph& graph) {
  for (int i = 0; i < graph.size(); i++) {
    cout << i << "--> ";
    for (int j = 0; j < graph[i].size(); j++) {
      cout << graph[i][j].second << '-' << graph[i][j].first << ' ';
    }
    cout << endl;
  }
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    Graph graph(n);
    for (int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      graph[u].push_back({c, v});
    }

    int x, y;
    cin >> x >> y;
    Adj res = dijkstra(graph, x, y);
    if (res.first == INT_MAX) cout << "no path from " << x << " to " << y << endl;
    else
      cout << "cost " << res.first << ", " << res.second << " way(s)" << endl;
  }
}
