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

// the k firsts positions of vector sol are fixed
void backtracking(int k, vector<int>& sol) {
  // If is solution then print it
  if (k == sol.size()) print(sol);
  else {
    sol[k] = 0; backtracking(k+1, sol);
    sol[k] = 1; backtracking(k+1, sol);
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> sol(n);
  backtracking(0, sol);
}
