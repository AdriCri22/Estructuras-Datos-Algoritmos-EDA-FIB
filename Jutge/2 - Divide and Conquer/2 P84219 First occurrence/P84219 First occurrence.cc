#include <iostream>
#include <vector>
using namespace std;

int binary_search(double x, const vector<double>& v, int l, int u) {
  if (l > u) return -1;  // x not belong to v

  int m = (l + u) / 2;
  if (x == v[m]) {  // x found
    // Check if x exists at a previous position
    int prev = binary_search(x, v, l, m - 1);
    if (prev != -1) return prev;  // Exist x at a previous position
    else return m;  // Not exist x at a previous position
  }
  else if (x < v[m]) return binary_search(x, v, l, m - 1);
  else return binary_search(x, v, m + 1, u);
}

int first_occurrence(double x, const vector<double>& v) {
  return binary_search(x, v, 0, v.size() - 1);
}

int main() {
  int n;
  cin >> n;
  vector<double> v(n);

  for (int i = 0; i < n; i++) cin >> v[i];

  double x;
  cin >> x;
  cout << first_occurrence(x, v) << endl;
}
