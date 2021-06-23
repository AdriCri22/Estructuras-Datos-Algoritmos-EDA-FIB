#include<iostream>
#include<set>
using namespace std;

int main() {
  set<string> seq;
  string elem;
  auto med = seq.begin();
  while (cin >> elem and elem != "END") {
    auto it = seq.insert(elem).first;
    if (med == seq.end()) med = it;
    else if (seq.size() % 2 == 0 and elem < *med) med--;
    else if (seq.size() % 2 != 0 and elem > *med) med++;
    cout << *med << endl;
  }
}
