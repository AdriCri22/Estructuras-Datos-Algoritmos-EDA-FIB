#include <iostream>
#include <vector>
using namespace std;


int k_esim(int k, const vector<vector<int> >& V);


int main() {
  int n;
  while (cin >> n) {
    vector<vector<int> > V(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      total += m;
      V[i] = vector<int>(m);
      for (int j = 0; j < m; ++j) cin >> V[i][j];
    }

    int i1, i2, k;
    while (cin >> i1 >> i2 >> k, i1 != -1) {
      if (i1 < 0 or i1 >= n or i2 < 0 or i2 >= n or k < 1 or k > total) {
        cerr << "pifia!!! " << i1 << ' ' << i2 << ' ' << k << ' ' << n
             << ' ' << total << endl;
        return 0;
      }

      swap(V[i1], V[i2]);
      cout << k_esim(k, V) << endl;
    }
  }
}
