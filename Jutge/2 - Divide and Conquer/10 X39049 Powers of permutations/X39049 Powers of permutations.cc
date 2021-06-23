#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i != v.size() - 1) cout << ' ';
  }
  cout << endl;
}

// pi = σ(Ti)
// Ejemplo: σ = {1, 2, 0}   T = {2, 0, 1}
// p0 = σ(T0) = σ2 = 0
// buscamos la posición 0 => Ti dónde i = 0, en la posición 0 en T está el valor 2 =>
// => buscamos σi dónde i = 2, en la posición 2 en σ está el valor 0 => p0 = 0
void product(vector<int>& S, const vector<int>& T) {
  vector<int> P(S.size());
  for (int i = 0; i < P.size(); i++)
    P[i] = S[T[i]];   // σ(Ti)

  for (int i = 0; i < S.size(); i++) S[i] = P[i];
}

vector<int> permutation(const vector<int>& V, int k) {
  vector<int> R;
  if (k == 0) {
    for (int i = 0; i < V.size(); i++) R.push_back(i);
    return R;
  }

  R = permutation(V, k / 2);
  if (k % 2 == 0) product(R, R);
  else {
    product(R, R);
    product(R, V);
  }
  return R;
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int k;
    cin >> k;
    vector<int> res = permutation(v, k);
    write(res);
  }
}
