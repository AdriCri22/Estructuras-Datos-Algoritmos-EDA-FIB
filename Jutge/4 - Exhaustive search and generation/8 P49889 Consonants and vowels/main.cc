#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> V;

bool can_be_placed(int k, int l, const V& letters, const V& sol) {
  // Checks if already used
  for (int i = 0; i < k; i++)
    if (sol[i] == letters[l]) return false;

  // Checks if two vowels or consonants are placed consecutively
  if (k > 0 and k % 2 == 0 and l % 2 == 1) return false;
  else if (k > 0 and k % 2 == 1 and l % 2 == 0) return false;

  return true;
}

void print(const V& sol) {
  for (auto c : sol)
    cout << c;

  cout << endl;
}

void permutations(int k, const V& letters, V& sol) {
  if (k == sol.size()) print(sol);
  else {
    for (int i = 0; i < letters.size(); i++) {
      if (can_be_placed(k, i, letters, sol)) {
        sol[k] = letters[i]; permutations(k+1, letters, sol);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  V vowels(n), consonants(n), sol(2*n), letters(2*n);
  for (int i = 0; i < 2*n; i+=2) cin >> letters[i];
  for (int i = 1; i < 2*n; i+=2) cin >> letters[i];

  permutations(0, letters, sol);
}
