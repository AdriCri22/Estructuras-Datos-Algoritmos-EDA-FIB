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

bool BFS(Pos src, const Board& board) {
  // Indicates if some position has been visited
  vector<vector<bool> > vis(board.size(), vector<bool>(board[0].size(), false));
  vis[src.first][src.second] = true;  // Set the source position as visited
  queue<Pos> q;
  q.push(src);    // Add the source position to queue


  while (not q.empty()) {
    Pos p = q.front();
    q.pop();

    // If a treasure has been found, it return true
    if (board[p.first][p.second] == 't') return true;

    // For all adjacent positions (Down, Right, Up, Left)
    Positions adjacent = adjacents(p);
    for (auto pos : adjacent) {
      // Checks if it's a position on the board and hasn't been visited
      if (pos_ok(pos, board) and not vis[pos.first][pos.second]) {
        vis[pos.first][pos.second] = true;
        q.push(pos);
      }
    }
  }

  return false;    // There isn't a path
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

  // Search if exists a path to a treasure from initial pos
  if (BFS(Pos({r-1, c-1}), board)) cout << "yes" << endl;
  else cout << "no" << endl;
}
