#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

typedef vector<pair<int, int>> Col;
typedef vector<Col> Graph;

typedef pair<int, int> P;

int dijkstra(const Graph& graph, int x, int y) {
  vector<int> dist(graph.size(), INT_MAX);
  priority_queue<P, vector<P>, greater<P>> q;
  q.push({0, x});
  dist[x] = 0;

  while (not q.empty()) {
    auto t = q.top();  q.pop();
    int u = t.second, d = t. first;
    if (u == y) return dist[y];

    for (auto p : graph[u]) {
      int v = p.second, l = p. first;
      int d2 = max(dist[u], l);
      if (d2 < dist[v]) {
        dist[v] = d2;
        q.push({d2, v});
      }
    }
  }

  return INT_MAX;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    // pair<y, l>
    Graph graph(n);
    for (int i = 0; i < m; i++) {
      int x, y, l;
      cin >> x >> y >> l;

      graph[x].push_back({l, y});
    }

    cout << dijkstra(graph, 0, 1) << endl;
  }
}
