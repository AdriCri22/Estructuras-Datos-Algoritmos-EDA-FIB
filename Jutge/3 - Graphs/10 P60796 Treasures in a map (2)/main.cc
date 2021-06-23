#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> Col;
typedef vector<Col> Board;
typedef pair<int, int> Pos;
typedef vector<Pos> Positions;


Positions adjacents(Pos p) {
  Positions pos;
  pos.push_back({p.first+1, p.second});    // Down
  pos.push_back({p.first, p.second+1});    // Right
  pos.push_back({p.first-1, p.second});    // Up
  pos.push_back({p.first, p.second-1});    // Left
  return pos;
}

bool pos_ok(Pos p, const Board& board) {
  // Check that not overflows the board margins and is not a obstacle on the board
  if (0 <= p.first and p.first < board.size()
      and 0 <= p.second and p.second < board[0].size()
      and board[p.first][p.second] != 'X') return true;
  else return false;
}

int BFS(Pos src, const Board& board) {
  // Indicates if some position has been visited
  vector<vector<int> > dist(board.size(), vector<int>(board[0].size(), -1));
  dist[src.first][src.second] = 0;  // Set the source position as visited
  queue<Pos> q;
  q.push(src);    // Add the source position to queue

  while (not q.empty()) {
    Pos p = q.front();
    q.pop();

    // If a treasure has been found, it return true
    if (board[p.first][p.second] == 't') return dist[p.first][p.second];

    // For all adjacent positions (Down, Right, Up, Left)
    Positions adjacent = adjacents(p);
    for (auto pos : adjacent) {
      // Checks if it's a position on the board and hasn't been visited
      if (pos_ok(pos, board) and dist[pos.first][pos.second] == -1) {
        dist[pos.first][pos.second] = dist[p.first][p.second] + 1;
        q.push(pos);
      }
    }
  }

  return -1;    // There isn't a path
}

int main() {
  int n, m;
  cin >> n >> m;

  // Read board
  Board board(n, Col(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];

  // Get initial pos
  int r, c;
  cin >> r >> c;

  int res = BFS(Pos({r-1, c-1}), board);
  if (res == -1) cout << "no treasure can be reached" << endl;
  else cout << "minimum distance: " << res << endl;
}
