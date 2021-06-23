#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    istringstream ss(s);
    int num;
    set<int> seq;
    while (ss >> num) seq.insert(num);

    int last, count = 1;
    if (seq.empty()) count = 0;
    else  {
      for (auto it = seq.begin(); it != seq.end(); it++) {
        if (it == seq.begin()) last = *it;
        else if (*it > last and ((*it % 2 == 0 and last % 2 != 0) or
                    (*it % 2 != 0 and last % 2 == 0))) count++;
        last = *it;
      }
    }

    cout << count << endl;
  }
}
