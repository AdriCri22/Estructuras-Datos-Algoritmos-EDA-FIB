#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

void print(const VI& color) {
  cout << "--- Colored graph ---" << endl;
  for (int i = 0; i < color.size(); i++)
    cout << i << ' ' << color[i] << endl;

  cout << endl;
}

bool dfs_rec(const VVI& graph, VI& color, int u) {
  if (color[u] == 0) color[u] = 1;
  for (int v : graph[u]) {
    if (color[u] == color[v]) return false;
    if (color[v] == 0) {
      if (color[u] == 1) color[v] = 2;
      else color[v] = 1;
      if (not dfs_rec(graph, color, v)) return false;
    }
  }

  return true;
}

bool dfs(const VVI& graph) {
  VI color(graph.size(), 0);      // 0 = no color, 1 = color 1 and 2 = color 2
  bool cont = true;
  for (int u = 0; u < graph.size() and cont; u++)
    if (color[u] == 0)
      cont = dfs_rec(graph, color, u);

  return cont;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    VVI graph(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;

      graph[x].push_back(y);
      graph[y].push_back(x);
    }

    if (dfs(graph)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
