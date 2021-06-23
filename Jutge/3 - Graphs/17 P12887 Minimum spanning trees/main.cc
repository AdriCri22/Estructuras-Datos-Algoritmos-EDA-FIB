#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// pair<weight, node>
typedef pair<int, int> P;

int mst(const vector<vector<P>>& G) {
  vector<bool> vis(G.size(), false);
  // queue that order the inputs by wieght (first element weightless)
  priority_queue<P, vector<P>, greater<P>> q;

  // Push to queue all adjacent vertices of first node
  for (auto p : G[0]) q.push(p);
  vis[0] = true;  // Sets first node as visited

  int sum = 0;    // Sum of weights
  int count = 1;  // Count to visit all nodes
  while (count < G.size()) {
    P p = q.top();
    q.pop();

    int w = p.first;  // Get weight
    int v = p.second; // Get node
    if (not vis[v]) {
      vis[v] = true;
      for (auto p : G[v]) q.push(p);
      sum += w;
      count++;
    }
  }
  return sum;
}



void print_adjacency_list(const vector<vector<P>>& G) {
  for (int i = 0; i < G.size(); i++) {
    cout << i+1 << "--->  ";
    for (int j = 0; j < G[i].size(); j++)
      cout << G[i][j].first << ' ' << G[i][j].second+1 << "   ";

    cout << endl;
  }
}

int main() {
  // n is the number of nodes and m the number of edges
  int n, m;
  while (cin >> n >> m) {
    // vector containing at position i (node u) the nodes to which it is connected
    // with their respective weights
    vector<vector<P>> G(n);

    // Set of m weighted edges
    for (int i = 0; i < m; i++) {
      // u and v are the vertices and w the weight
      int u, v, w;
      cin >> u >> v >> w;
      u--; v--;

      G[u].push_back({w, v});
      G[v].push_back({w, u});
    }

    cout << mst(G) << endl;
  }
}
