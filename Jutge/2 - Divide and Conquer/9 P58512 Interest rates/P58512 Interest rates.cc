#include <iostream>
using namespace std;

double power(double a, int n) {
  if (n == 0) return 1;

  double x = power(a, n / 2);
  if (n % 2 == 0) return (x * x);
  else return (x * x * a);
}

int num_days(double m, double f, double i, int l, int u) {
  if (l <= u) {
    int mid = (u + l) / 2;
    double mBank = power(i, mid) * m;
    double mPers = f * mid + m;
    if (mPers > mBank) return num_days(m, f, i, mid + 1, u);
    if (mPers < mBank) return num_days(m, f, i, l, mid - 1);
    return mid;
  }

  return l;
}

int main(){
  double m, f, r;
  while(cin >> m >> f >> r)
    cout << num_days(m, f, (r / 100 + 1), 1, 100000000) << endl;
}
