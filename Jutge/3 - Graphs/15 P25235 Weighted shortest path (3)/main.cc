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
  // Array of distance between the source and other nodes
  vector<int> dist(graph.size(), INT_MAX);
  dist[src] = 0;    // Set the source node as distance 0
  vector<int> steps(graph.size(), 0);
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
        steps[v] = steps[u] + 1;
        q.push({dist[v], v});
      }
      // The statement omits (not like the previous one) that only exists a unique path
      else if (dist[v] == dist[u] + w and steps[v] > steps[u] + 1)
        steps[v] = steps[u] + 1;
    }
  }

  return {dist[des], steps[des]};
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
      cout << "cost " << res.first << ", " << res.second << " step(s)" << endl;
  }
}
