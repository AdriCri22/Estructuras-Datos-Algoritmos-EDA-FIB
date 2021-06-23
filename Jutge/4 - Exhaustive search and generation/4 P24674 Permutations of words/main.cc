#include <iostream>
#include <vector>
using namespace std;

void print(const vector<string>& sol) {
  for (int i = 0; i < sol.size(); i++) {
    if (i == 0) cout << '(';
    else cout << ',';
    cout << sol[i];
    if (i == sol.size()-1) cout << ')';
  }
  cout << endl;
}

bool already_used(int k, string word, const vector<string>& sol) {
  for (int i = 0; i < k; i++)
    if (sol[i] == word) return true;

  return false;
}

void perm_words(int k, const vector<string>& words, vector<string>& sol) {
  // If a solution has been found then print it out
  if (k == sol.size()) print(sol);
  else {
    for (auto s : words) {
      if (not already_used(k, s, sol)) {
        sol[k] = s; perm_words(k+1, words, sol);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<string> words(n);
  for (int i = 0; i < n; i++) cin >> words[i];

  vector<string> sol(n);
  perm_words(0, words, sol);
}
