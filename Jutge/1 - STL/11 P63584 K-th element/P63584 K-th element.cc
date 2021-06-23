#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int k_esim(int k, const VVI& V) {
  // map with number and the row and column in V
  map<int, pair<int, int> > nums;
  // get for each row the minimum element
  for (int i = 0; i < V.size(); i++)
    if (not V[i].empty()) nums[V[i][0]] = make_pair(i, 0);

  // While is not the k-th smaller element in the array
  while (1 < k) {
    // Get the smaller element in the map
    pair<int, int> min = nums.begin()->second;
    // Remove the smaller element in the map
    nums.erase(nums.begin());
    // Get the next smaller element in the row
    if (++min.second < V[min.first].size())
      nums[V[min.first][min.second]] = make_pair(min.first, min.second);

    k--;
  }

  return nums.begin()->first;
}

int main() {
  int n;
  cin >> n;
  VVI V(n);

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int num;
      cin >> num;
      V[i].push_back(num);
    }
  }

  int k;
  cin >> k;

  cout << k_esim(k, V) << endl;
}
