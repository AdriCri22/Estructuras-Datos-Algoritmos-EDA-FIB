#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> Adj;
typedef vector<Adj> Graph;
typedef vector<bool> Visited;

bool DFS_REC(const Graph& graph, Visited& vis, Visited& stack, int u) {
  vis[u] = true;
  stack[u] = true;
  for (int v : graph[u])
    if (not vis[v] and DFS_REC(graph, vis, stack, v))
      return true;
    else if (stack[v])
      return true;

  stack[u] = false;
  return false;
}

bool DFS(const Graph& graph) {
  Visited vis(graph.size(), false);
  Visited stack(graph.size(), false);
  for (int u = 0; u < graph.size(); u++)
    if (not vis[u] and DFS_REC(graph, vis, stack, u))
      return true;

  return false;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    Graph graph(n);
    for (int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      graph[u].push_back(v);
    }
    if (DFS(graph)) cout << "yes" << endl;
    else cout << "no" << endl;
  }

}
