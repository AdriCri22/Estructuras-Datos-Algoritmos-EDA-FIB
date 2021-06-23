#include <iostream>
#include <set>
using namespace std;

struct comp {
  bool operator() (const string& s1, const string& s2) const {
    if (s1.size() < s2.size()) return true;
    else if (s1.size() > s2.size()) return false;
    else return s1 < s2;
  }
};

void print(set<string>& has, set<string, comp>& had, int& count, bool final) {
  cout << "GAME #" << count << endl << "HAS:" << endl;
  for (auto it = has.begin(); it != has.end(); it++)
    cout << *it << endl;
  cout << endl << "HAD:" << endl;
  for (auto it = had.begin(); it != had.end(); it++)
    cout << *it << endl;
  if (not final) cout << endl;
  has.clear();
  had.clear();
  count++;
}

int main() {
  string str;
  int count = 1;
  set<string> has;
  set<string, comp> had;
  while (cin >> str and str != "QUIT") {
    if (str == "END") print(has, had, count, false);
    else {
      auto it = has.find(str);
      if (it == has.end()) {
        has.insert(str);
        it = had.find(str);
        if (it != had.end()) had.erase(it);
      } else {
        has.erase(it);
        it = had.find(str);
        if (it == had.end()) had.insert(str);
      }
    }
  }
  print(has, had, count, true);
}
