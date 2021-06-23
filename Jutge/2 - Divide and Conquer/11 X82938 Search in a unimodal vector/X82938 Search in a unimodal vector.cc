#include <iostream>
#include <vector>
using namespace std;

int search_j(const vector<int>& v, int l, int u) {
  if (u - l == 0) return u;
  if (u - l == 1) {
    if (v[l] > v[u]) return l;
    else return u;
  }

  int m = (u + l) / 2;
  if (v[m - 1] < v[m] and v[m] < v[m + 1]) return search_j(v, m + 1, u);
  if (v[m - 1] > v[m] and v[m] > v[m + 1]) return search_j(v, l, m - 1);
  else return m;
}

bool binary_search(const vector<int>& v, int x, int l, int u, bool asc) {
  if (l > u) return false;     // x not belong to v

  int m = (l + u) / 2;
  if (x == v[m]) return true;
  if ((x < v[m] and asc) or (x > v[m] and not asc))
    return binary_search(v, x, l, m - 1, asc);
  return binary_search(v, x, m + 1, u, asc);
}

bool search(int x, const vector<int>& v) {
  int j = search_j(v, 0, v.size() - 1);
  return binary_search(v, x, 0, j, true) or binary_search(v, x, j, v.size() - 1, false);
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}
