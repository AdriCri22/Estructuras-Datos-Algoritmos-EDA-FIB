#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

void dfs(const VVI& graph, VB& vis, int x) {
  if (vis[x]) return;
  vis[x] = true;
  for (int y : graph[x])
    dfs(graph, vis, y);
}

int main() {
  int n, u, v, m;
  while (cin >> n >> u >> v >> m) {
    VVI graph(n);
    VVI inverted(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;

      graph[x].push_back(y);
      inverted[y].push_back(x);
    }

    VB fwd(n, false);
    dfs(graph, fwd, u);
    if (not fwd[v]) cout << 0 << endl;
    else {
      VB bwd(n, false);
      dfs(inverted, bwd, v);
      int count = 0;
      for (int w = 0; w < n; w++)
        if (fwd[w] and bwd[w])
          count++;

      cout << count - 2 << endl;
    }


  }
}
