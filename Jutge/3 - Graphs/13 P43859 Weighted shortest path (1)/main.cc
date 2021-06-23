#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

// pair<cost, node>
typedef pair<int, int> Adj;

typedef vector<Adj> Col;
typedef vector<Col> Graph;

int dijkstra(const Graph& graph, int src, int des) {
  // Array of distance between the source and other nodes
  vector<int> dist(graph.size(), INT_MAX);
  dist[src] = 0;    // Set the source node as distance 0
  // Creates a queue ordered by distance increasingly pair<dist, node>
  priority_queue<Adj, vector<Adj>, greater<Adj>> q;
  q.push({0, src});   // Add the source node to queue

  while (not q.empty()) {
    Adj adj = q.top();
    q.pop();

    int u = adj.second;
    for (auto adj2 : graph[u]) {
      int v = adj2.second;
      int w = adj2.first;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        q.push({dist[v], v});
      }
    }
  }

  return dist[des];
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
    int res = dijkstra(graph, x, y);
    if (res == INT_MAX) cout << "no path from " << x << " to " << y << endl;
    else cout << res << endl;
  }
}
