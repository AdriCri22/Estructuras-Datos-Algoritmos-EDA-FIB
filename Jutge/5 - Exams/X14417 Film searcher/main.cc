#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<int> VI;
typedef vector<VI> VVI;

struct Pos {
  int x;
  int y;
};

vector<Pos> Dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

Pos getPos(Pos p, Pos d) {
  return Pos({p.x + d.x, p.y + d.y});
}

bool pos_ok(const VVS& board, Pos p) {
  if (0 <= p.x and p.x < board.size() and 0 <= p.y and p.y < board[0].size()
        and board[p.x][p.y] != "*")
    return true;
  else
    return false;
}

int bfs(const VVS& searcher, const Pos& src, const Pos& dest) {
  VVI dist(searcher.size(), VI(searcher[0].size(), -1));
  dist[src.x][src.y] = 0;
  queue<Pos> q;
  q.push(src);

  while (not q.empty()) {
    Pos pos = q.front();   q.pop();

    if (pos.x == dest.x and pos.y == dest.y)
      return dist[pos.x][pos.y];

    for (Pos d : Dir) {
      Pos p2 = getPos(pos, d);
      if (pos_ok(searcher, p2) and dist[p2.x][p2.y] == -1) {
        dist[p2.x][p2.y] = dist[pos.x][pos.y] + 1;
        q.push(p2);
      }
    }
  }

  return -1;
}

Pos positionWord(const VVS& board, const string& word) {
  for (int i = 0; i < board.size(); i++)
    for (int j = 0; j < board[0].size(); j++)
      if (board[i][j] == word) return {i, j};

  return {-1, -1};
}

int cursor(const VVS& searcher, const VS& words) {
  vector<Pos> positions(words.size() + 1);
  positions[0] = {0, 0};
  for (int i = 0; i < words.size(); i++) {
    Pos p = positionWord(searcher, words[i]);
    if (p.x == -1)
      return -1;
    else
      positions[i + 1] = p;
  }

  int sum = 0;
  for (int i = 0; i < positions.size() - 1; i++) {
    int res = bfs(searcher, positions[i], positions[i + 1]);
    if (res == -1) return -1;
    else sum += res + 1;
  }

  return sum;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    VVS searcher(n, VS(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> searcher[i][j];

    int p;  cin >> p;
    VS words(p);
    for (int i = 0; i < p; i++)
      cin >> words[i];

    int res = cursor(searcher, words);
    if (res == -1) cout << "impossible" << endl;
    else cout << res << endl;
  }
}
