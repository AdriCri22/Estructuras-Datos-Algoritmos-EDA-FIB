#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& v, int l, int m, int u) {
  vector<int> M(u - l + 1);

  int i = l, j = m + 1, k = 0, count = 0;;
  while (i <= m and j <= u) {
    if (v[i] <= v[j]) M[k++] = v[i++];
    // If the number that goes before is bigger
    else {
      M[k++] = v[j++];
      // Increment the counter with the number of positions that advances
      count += m + 1 - i;
    }
  }

  while (i <= m) M[k++] = v[i++];
  while (j <= u) M[k++] = v[j++];

  for (int k = 0; k < (u - l + 1); k++) v[l + k] = M[k];

  return count;
}

int mergeSort(vector<int>& v, int l, int u) {
  int count  = 0;
  if (l < u) {
    int m = (l + u) / 2;
    count = mergeSort(v, l, m);
    count += mergeSort(v, m + 1, u);
    count += merge(v, l, m, u);
  }

  return count;
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    cout << mergeSort(v, 0, n - 1) << endl;
  }
}
