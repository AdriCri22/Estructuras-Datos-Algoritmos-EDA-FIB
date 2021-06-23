#include <iostream>
#include <vector>
using namespace std;

int fixed_point(const vector<int>& S, int a, int l, int u) {
  if (l > u) return -1;

  int m = (l + u) / 2;
  if ((S[m] + a) == m + 1) {
    int prev = fixed_point(S, a, l, m - 1);
    if (prev != -1) return prev;
    else return m + 1;
  }
  else if ((S[m] + a) > m + 1) return fixed_point(S, a, l, m - 1);
  else return fixed_point(S, a, m + 1, u);
}

int main() {
  int n;
  int count = 1;
  while (cin >> n) {
    vector<int> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];

    int m;
    cin >> m;
    cout << "Sequence #" << count << endl;
    for (int i = 0; i < m; i++) {
      int a;
      cin >> a;

      int res = fixed_point(S, a, 0, S.size() - 1);
      if (res != -1)
        cout << "fixed point for " << a << ": " << res << endl;
      else
        cout << "no fixed point for " << a << endl;
    }

    cout << endl;
    count++;
  }
}
