#include <iostream>
#include <vector>
using namespace std;

bool already_used(const vector<int>& v, int k) {
  for (int x : v)
    if (x == k)
      return true;

  return false;
}

void print(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (i == 0) cout << '(';
    else cout << ',';

    cout << v[i];

    if (i == v.size() - 1) cout << ')';
  }
  cout << endl;
}

void perm(const vector<int>& v, vector<int>& sol, int k) {
  if (sol.size() == v.size()) print(sol);
  else {
    for (int x : v) {
      if (not already_used(sol, x)) {
        if (k < 2 or (k >= 2 and (sol[k-2] + x <= 2 * sol[k-1]))) {
          sol.push_back(x);
          perm(v, sol, k+1);
          sol.pop_back();
        }
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    v[i] = i + 1;

  vector<int> sol;

  perm(v, sol, 0);
}
