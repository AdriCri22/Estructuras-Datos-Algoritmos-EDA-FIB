#include <iostream>
using namespace std;

//n^k mod m.
int exponentMod(int n, int k, int m) {
  if (k == 0) return 1; // n^0 = 1
  if (n == 0) return 0; // 0^k = 0

  int res;
  // Property 1:    (a * b) mod m = [(a mod m) * (b mod m)] mod m
  if (k % 2 == 0) {
    // Property 2 if is even:   n^k mod m = [(n^(k/2)) * (n^(k/2))] mod m
    res = exponentMod(n, k / 2, m);
    res = (res * res) % m;
  } else {
    // Property 2 if is odd:    n^k mod m = [n * (n^(k-1))] mod m
    res = n % m;
    res = (res * exponentMod(n, k - 1, m) % m) %m;
  }

  // Property 3:  If we have to return the mod of negative number res whose
  //              absolute value is less than m => (res + m) % m
  return (res + m) % m;
}


int main() {
  int n, k, m;
  while (cin >> n >> k >> m)
    cout << exponentMod(n, k, m) << endl;
}
