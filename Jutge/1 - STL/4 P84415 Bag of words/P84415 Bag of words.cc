#include<iostream>
#include<map>
using namespace std;

int main() {
  map<string, int> words;
  string op;
  while (cin >> op) {
    if (op == "maximum?") {
      if (words.empty()) cout << "indefinite maximum" << endl;
      else {
        auto it = words.end();
        it--;
        cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
      }
    } else if (op == "minimum?") {
      if (words.empty()) cout << "indefinite minimum" << endl;
      else
        cout << "minimum: " << words.begin()->first << ", " << words.begin()->second << " time(s)" << endl;
    } else if (op == "delete") {
      string word;
      cin >> word;
      if (words[word] <= 1) words.erase(word);
      else words[word]--;
    } else if (op == "store") {
      string word;
      cin >> word;
      words[word]++;
    }
  }
}
