#include <iostream>
#include <map>
using namespace std;

void next_n(int x, int y, int& n) {
  if (n % 2 ==0) n = n / 2 + x;
  else n = 3 * n + y;
}

int main() {
  int x, y, n;

  while (cin >> x >> y >> n) {
    map<int, int> numbers; // number and position
    numbers[n] = 0;

    int pos = 1;
    bool found = false;
    while (n <= 100000000 and not found) {
      next_n(x, y, n);
      auto it = numbers.find(n);
      found = it != numbers.end(); // Check if exist a cycle
      /* The cycle is the rest between the actual position (pos) and
      the position of the new number that is repeated */
      if (found) n = pos - it->second;
      else {
        numbers[n] = pos;
        pos++;
      }
    }
    cout << n << endl;
  }
}
