#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
  if (left > right) return -1;

  int m = (right + left) / 2;
  if (x == v[m]) return m;
  else if (x < v[m]) return position(x, v, left, m - 1);
  else return position(x, v, m + 1, right);
}

int main() {
  int n, left, right;
  cin >> n;
  vector<double> v(n);

  for (int i = 0; i < n; i++) cin >> v[i];

  double x;
  cin >> x >> left >> right;
  cout << position(x, v, left, right) << endl;
}
