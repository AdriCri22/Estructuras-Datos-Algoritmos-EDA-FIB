#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

// k are the k positions placed in the vector sol
void backtracking(int i, int sum, int res, int& count, const VI& nums, VB& n1, VB& n2) {
  if (sum == res) count++;
  else if (sum <= res and i < nums.size() and nums[i]+sum <= res) {
    if (not n1[i]) {
      n1[i] = true;
      backtracking(i, sum+nums[i], res, count, nums, n1, n2);
      n1[i] = false;
    }

    else if (not n2[i]) {
      n2[i] = true;
      backtracking(i+1, sum+nums[i], res, count, nums, n1, n2);
      n2[i] = false;
    }

    backtracking(i+1, sum, res, count, nums, n1, n2);

  }
}

void merge(VI& T, int l, int m, int u) {
	VI B(u - l + 1);
	int i = l, j = m + 1, k = 0;
	while (i <= m and j <= u) {
		if (T[i] <= T[j]) B[k++] = T[i++];
		else B[k++] = T[j++];
	}

	while (i <= m) B[k++] = T[i++];
	while (j <= u) B[k++] = T[j++];

	for (k = 0; k <= u - l; ++k) T[l + k] = B[k];
}

void mergesort(VI& T, int l, int u) {
	if (l < u) {
		int m = (l + u) / 2;
		mergesort(T, l, m);
		mergesort(T, m + 1, u);
		merge(T, l, m, u);
	}
}

int main() {
  int x, n;
  while (cin >> x >> n) {
    VI nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    // Sort the numbers increasenly
    mergesort(nums, 0, n - 1);

    VI sol(2*n);
    VB n1(n, false), n2(n, false);
    int count = 0;
    backtracking(0, 0, x, count, nums, n1, n2);
    cout << count << endl;
  }
}
