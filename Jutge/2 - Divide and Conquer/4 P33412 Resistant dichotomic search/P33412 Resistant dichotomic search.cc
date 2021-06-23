#include <iostream>
#include <vector>
using namespace std;

bool binary_search(double x, const vector<double>& v, int l, int u) {
  if (l > u) return false;  // x not belong at v

  int m = (l + u) / 2;
  if (x == v[m]) return true;
  else if ((m - 1) >= 0 and x == v[m - 1]) return true;
  else if ((m + 1) <= (v.size() - 1) and x == v[m + 1]) return true;
  else if (x < v[m]) return binary_search(x, v, l, m - 1);
  else return binary_search(x, v, m + 1, u);
}

bool resistant_search(double x, const vector<double>& v) {
  return binary_search(x, v, 0, v.size() - 1);
}

int main() {
  int n;
  cin >> n;
  vector<double> v(n);

  for (int i = 0; i < n; i++) cin >> v[i];

  double x;
  cin >> x;
  if (resistant_search(x, v)) cout << "true" << endl;
  else cout << "false" << endl;
}
