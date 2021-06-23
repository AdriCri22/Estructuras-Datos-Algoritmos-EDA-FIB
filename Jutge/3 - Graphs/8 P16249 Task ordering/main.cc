#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef vector<int> Adj;
typedef vector<Adj> Graph;
typedef map<string, int> Words;
typedef map<int, string> Nodes;

// The graph is an adjacency list
vector<string> topological_sort(const Graph& graph, Words& words, Nodes& nodes) {
  // Array of predecesors
  vector<int> pred(graph.size(), 0);
  for (int u = 0; u < graph.size(); u++)
    for (int v : graph[u])
      pred[v]++;

  // Priority queue because we need it to be in lexicographical order
  priority_queue<string, vector<string>, greater<string>> q;
  Words::const_iterator it;
  for (it = words.begin(); it != words.end(); it++) // Add all nodes without predecesors
    if (pred[it->second] == 0)
      q.push(it->first);

  vector<string> top_sort;
  while (not q.empty()) {
    string u = q.top();
    q.pop();
    top_sort.push_back(u);   // Adds the node to list

    for (int v : graph[words[u]])    // For all Adjacent nodes
      if (--pred[v] == 0)     // If num of predecesors not visited = 0
        q.push(nodes[v]);            // Adds to stack
  }

  return top_sort;
}

int main() {
  int n;
  while (cin >> n) {
    Words words;   // map<word, node_int>
    Nodes nodes;   // map<node_int, word>
    for (int i = 0; i < n; i++) {
      string word; cin >> word;
      words[word] = i;
      nodes[i] = word;
    }

    Graph graph(n);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
      string x, y;
      cin >> x >> y;
      graph[words[x]].push_back(words[y]);
    }

    vector<string> top_sort = topological_sort(graph, words, nodes);
    if (top_sort.size() == n)
      for (auto word : top_sort)
        cout << word;

    else cout << "NO VALID ORDERING";

    cout << endl;
  }
}
