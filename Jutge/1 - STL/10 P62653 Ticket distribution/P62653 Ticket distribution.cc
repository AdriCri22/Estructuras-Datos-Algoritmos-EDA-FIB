#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

string w;
struct comp {
  bool operator() (const string& s1, const string& s2) {
    if (s1.length() == s2.length()) {
      string substr = w.substr(0, s1.length());
      if (s1 == substr) return false;
      else if (s2 == substr) return true;
      else if (s1 < s2) {
        if (s1 < substr and s2 > substr) return true;
        else return false;
      } else {
        if (s1 > substr and s2 < substr) return false;
        else return true;
      }
    } else return s1.length() > s2.length();
  }
};

int main() {
  while (cin >> w) {
    string name;
    int tickets = 0;
    char op;
    priority_queue<string, vector<string>, comp> record;
    while (cin >> op and op != 'E') {
      if (op == 'S') {
        cin >> name;
        record.push(name);
      } else tickets++;

      while (0 < tickets and not record.empty()) {
        cout << record.top() << endl;
        record.pop();
        tickets--;
      }
    }

    cout << tickets << " ticket(s) left" << endl;
    cout << record.size() << " supporter(s) with no ticket" << endl << endl;
  }
}
