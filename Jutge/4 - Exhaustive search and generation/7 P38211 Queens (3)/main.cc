#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> V;
typedef vector<int> VV;

void print(VV& row, V& col) {
  for (int i = 0; i < row.size(); i++) {
    for (int j = 0; j < col.size(); j++) {
      if (row[i] == j) cout << 'Q';
      else cout << '.';
    }
    cout << endl;
  }
}

// q are the number of queens placed
// sum are the number of ways that the queens can be placed in the chessboard
void backtracking(int q, bool& found, VV& row, V& col, V& diag_up, V& diag_down) {
  int n = row.size();
  if (found) return;

  // If the number of queens equal to the queens requested increment the sum variable
  if (q == n) {
    print(row, col);
    found = true;
  } else {
    for (int i = 0; i < n; i++) {
      if (not col[i] and not diag_up[i+q] and not diag_down[q-i+n-1]) {
        col[i] = diag_up[i+q] = diag_down[q-i+n-1] = true;
        row[q] = i;     // Only necessary for printing
        backtracking(q+1, found, row, col, diag_up, diag_down);
        col[i] = diag_up[i+q] = diag_down[q-i+n-1] = false;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  VV row(n, false);
  V col(n, false), diag_up(n, false), diag_down(n, false);
  bool found = false;
  backtracking(0, found, row, col, diag_up, diag_down);
  if (not found) cout << "NO SOLUTION" << endl;
}
