#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;
Matrix Identity = {  {1, 0},  {0, 1}  };  // Identitiy matrix

Matrix product(Matrix A, Matrix B) {
  Matrix R(2, Row(2));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        R[i][j] += A[i][k] * B[k][j];

  return R;
}

Matrix mod(Matrix M, int m) {
  Matrix R(2, Row(2));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      R[i][j] = M[i][j] % m;
  return R;
}

Matrix matrix_exp(Matrix M, int n, int m) {
  if (n == 0) return Identity;

  if (n % 2 == 1) {
    Matrix R = product(M, matrix_exp(M, n - 1, m));
    return mod(R, m);
  } else {
    Matrix R = matrix_exp(M, n / 2, m);
    R = product(R, R);
    return mod(R, m);
  }
}

int main() {
  Matrix M(2, Row(2));
  while (cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1]) {
    int n, m;
    cin >> n >> m;

    Matrix A = matrix_exp(M, n, m);
    cout << A[0][0] << " " << A[0][1] << endl;
    cout << A[1][0] << " " << A[1][1] << endl;
    cout << "----------" << endl;
  }
}
