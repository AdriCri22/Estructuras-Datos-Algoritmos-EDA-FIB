#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    if (i == 0) cout << '(';
    else cout << ',';

    cout << v[i];

    if (i == n - 1) cout << ')';
  }
  cout << endl;
}

int absolute_substraction(int a, int b) {
  if (a < b) return b - a;
  else return a - b;
}

bool already_used(const vector<int>& V, int k) {
  for (auto v : V)
    if (v == k)
      return true;

  return false;
}

void balanced_permutation(const vector<int>& V, vector<int>& sol, int d, int k) {
  if (V.size() == k) print(sol);
  else {
    for (auto v : V) {
      if (not already_used(sol, v)) {
        if ((k != 0 and absolute_substraction(sol.back(), v) <= d) or k == 0) {
          sol.push_back(v);
          balanced_permutation(V, sol, d, k + 1);
          sol.pop_back();
        }
      }
    }
  }
}

int main() {
  int n, d;
  cin >> n >> d;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    v[i] = i + 1;

  vector<int> sol;
  balanced_permutation(v, sol, d, 0);
}
