#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& sol) {
  for (int i = 0; i < sol.size(); i++) {
    if (i == 0) cout << sol[i];
    else cout << ' ' << sol[i];
  }
  cout << endl;
}

// k number of setted positions
// t number of ones in the vector sol
// n number of ones that has to be in the vector sol
void backtracking(int k, int t, int o, vector<int>& sol) {
  // If the number of ones can't by fitted in the rest of positions the
  // partial solution is wrong
  if (sol.size() - k < o - t) return;
  // If is solution then print it
  else if (k == sol.size()) print(sol);
  // If the number of ones is equal to number of ones requested then the rest
  // of the solution are zeros
  else if (t == o) {
    sol[k] = 0; backtracking(k+1, t, o, sol);
  } else {
    sol[k] = 0; backtracking(k+1, t, o, sol);
    sol[k] = 1; backtracking(k+1, t+1, o, sol);
  }
}

int main() {
  int n, o;
  cin >> n >> o;

  vector<int> sol(n);
  backtracking(0, 0, o, sol);
}
