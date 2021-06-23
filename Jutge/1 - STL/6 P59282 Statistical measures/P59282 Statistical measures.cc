#include <iostream>
#include <queue>
using namespace std;

void print_statics(int min, int max, int count, double sum) {
  cout << "minimum: " << min << ", maximum: " << max;
  cout.setf(ios::fixed);
  cout.precision(4);
  cout << ", average: " << (double) sum / count << endl;
}

int main() {
  priority_queue<int, vector<int>, greater<int> > numbers;
  double sum = 0;
  int min = 0, max = 0, count = 0;
  bool first = true;

  string op;
  while (cin >> op) {
    if (op == "number") {
      int number;
      cin >> number;
      if (first) {
        first = false;
        max = number;
        min = number;
      } else {
        if (max < number) max = number;
        if (min > number) min = number;
      }
      numbers.push(number);
      sum += number;
      count++;
      print_statics(min, max, count, sum);
    } else if (op == "delete" and count > 0) {
      int n = numbers.top();
      numbers.pop();
      count--;
      sum -= n;
      if (count == 0) {
        first = true;
        cout << "no elements" << endl;
      } else {
        min = numbers.top();
        print_statics(min, max, count, sum);
      }
    } else cout << "no elements" << endl;
  }
}
