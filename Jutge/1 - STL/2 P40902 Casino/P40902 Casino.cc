#include<iostream>
#include<map>
using namespace std;

int main() {
  map<string, int> casino;
  string op;
  string name;
  while (cin >> name >> op and op != ".") {
    if (op == "enters") {
      auto it = casino.find(name);
      if (it == casino.end()) casino[name];
      else cout << name << " is already in the casino" << endl;
    } else if (op == "leaves") {
      auto it = casino.find(name);
      if (it != casino.end()) {
        cout << it->first << " has won " << it->second << endl;
        casino.erase(it);
      }
      else cout << name << " is not in the casino" << endl;
    } else if (op == "wins") {
      int n;
      cin >> n;
      auto it = casino.find(name);
      if (it != casino.end())
          it->second = it->second + n;
      else cout << name << " is not in the casino" << endl;
    }
  }
    cout << "----------" << endl;
    for (const auto &it : casino)
      cout << it.first << " is winning " << it.second << endl;
}
