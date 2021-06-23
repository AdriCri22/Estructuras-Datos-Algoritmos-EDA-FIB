#include<iostream>
#include<queue>
using namespace std;

int main() {
  priority_queue<int> q;
  char op;
  int n;
  while (cin >> op) {
    if (op == 'A') {
      if (q.empty()) cout << "error!" << endl;
      else cout << q.top() << endl;
    } else if (op == 'S') {
      cin >> n;
      q.push(n);
    } else if (op == 'R') {
      if (q.empty()) cout << "error!" << endl;
      else q.pop();
    } else if (op == 'I') {
      if (q.empty()) cout << "error!" << endl;
      else {
        cin >> n;
        int greatest_value = q.top() + n;
        q.pop();
        q.push(greatest_value);
      }
    } else if (op == 'D') {
      if (q.empty()) cout << "error!" << endl;
      else {
        cin >> n;
        int greatest_value = q.top() - n;
        q.pop();
        q.push(greatest_value);
      }
    }
  }
}
