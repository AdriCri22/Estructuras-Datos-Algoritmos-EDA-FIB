#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& sol) {
  for (int i = 0; i < sol.size(); i++) {
    if (i == 0) cout << '(';
    else cout << ',';
    cout << sol[i];
    if (i == sol.size() - 1) cout << ')';
  }
  cout << endl;
}

bool already_used(int k, int n, const vector<int>& sol) {
  for (int i = 0; i < k; i++)
    if (sol[i] == n) return true;

  return false;
}

// k is the number of fitted numbers in the vector sol
void permutations(int k, vector<int>& sol) {
  // If we find a solution print it
  if (k == sol.size()) print(sol);
  else {
    for (int i = 1; i < sol.size() + 1; i++) {
      if (not already_used(k, i, sol)) {
        sol[k] = i; permutations(k+1, sol);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> sol(n);
  permutations(0, sol);
}
