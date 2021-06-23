#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

typedef vector<int> Adj;
typedef vector<Adj> Graph;

// The graph is an adjacency list
vector<int> topological_sort(const Graph& graph) {
  // Array of predecesors
  vector<int> pred(graph.size(), 0);

  // For all adjacent nodes of u to v add a predecesor to v
  for (int u = 0; u < graph.size(); u++)
    for (int v : graph[u])
      pred[v]++;

  // Priority queue because we need it to be in lexicographical order
  priority_queue<int, vector<int>, greater<int>> q;
  for (int u = 0; u < graph.size(); u++) // Add all nodes without predecesors
    if (pred[u] == 0)
      q.push(u);

  vector<int> nodes;
  while (not q.empty()) {
    int u = q.top();
    q.pop();
    nodes.push_back(u);   // Adds the node to list

    for (int v : graph[u])  // For all Adjacent nodes
      if (--pred[v] == 0)   // If num of predecesors not visited = 0
        q.push(v);          /// Adds to stack
  }

  return nodes;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    Graph graph(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      graph[x].push_back(y);
    }

    vector<int> nodes = topological_sort(graph);
    for (int i = 0; i < nodes.size(); i++) {
      if (i != 0) cout << ' ';
      cout << nodes[i];
    }
    cout << endl;
  }
}
