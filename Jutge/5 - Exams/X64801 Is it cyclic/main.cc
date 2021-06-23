#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

bool dfs_rec(const VVI& graph, VB& vis, int u) {

  cout << u << endl;

  if (not vis[u]) {
    vis[u] = true;
    for (int v : graph[u])
      if (vis[v] or dfs_rec(graph, vis, v))
        return true;

    vis[u] = false;
    return false;
  }

  return true;
}

bool dfs(const VVI& graph) {
  VB vis(graph.size(), false);
  for (int u = 0; u < graph.size(); u++)
    if (not vis[u] and dfs_rec(graph, vis, u))
      return true;

  return false;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    VVI graph(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;

      graph[x].push_back(y);
    }

    if (dfs(graph)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
