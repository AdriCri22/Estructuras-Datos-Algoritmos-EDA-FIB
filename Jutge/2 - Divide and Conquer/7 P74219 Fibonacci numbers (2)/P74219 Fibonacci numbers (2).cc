#include <iostream>
#include <vector>
using namespace std;

typedef vector<unsigned long> Row;
typedef vector<Row> Matrix;
Matrix Initial = { {1, 1}, {1, 0} };

void product(Matrix& A, const Matrix& B) {
  int n = A.size();
  Matrix R(n, Row(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        R[i][j] += A[i][k] * B[k][j];


  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      A[i][j] = R[i][j];
}

void mod(Matrix& M, int m) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      M[i][j] = M[i][j] % m;
}

void power(Matrix& F, int n, int m) {
  if (n == 0 or n == 1) return;

  power(F, n / 2, m);
  product(F, F);

  if (n % 2 == 1) product(F, Initial);
  mod(F, m);
}

//  ┏       ┓ n        ┏                       ┓
//    1   1               F(n + 1)      F(n)
//    1   0       =         F(n)      F(n - 1)
//  ┗       ┛          ┗                       ┛

int fib(int n, int m) {
  if (n == 0) return 0;

  Matrix F = Initial;
  power(F, n - 1, m);
  return F[0][0];
}

int main() {
  int n, m;
  while (cin >> n >> m)
    cout << fib(n, m) << endl;
}
