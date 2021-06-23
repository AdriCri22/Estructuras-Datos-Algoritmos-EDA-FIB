#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct Info {
  double x;
  double y;
  double r;
};

typedef vector<Info> Rocks;

bool can_jump(const Info& a, const Info& b, double d) {
  // √[(x_2 - x_1)^2 + (y_2 - y_1)^2] - r_1 - r_2
  return sqrt((b.x-a.x) * (b.x-a.x) + (b.y-a.y) * (b.y-a.y)) - a.r - b.r <= d;
}

int BFS(const Rocks& rocks, double d) {
  vector<int> dist(rocks.size(), -1);
  dist[0] = 0;
  queue<int> q;
  q.push(0);

  while (not q.empty()) {
    int u = q.front();
    q.pop();

    for (int w = 0; w < rocks.size(); w++) {
      if (dist[w] == -1 and can_jump(rocks[u], rocks[w], d)) {
        dist[w] = dist[u] + 1;
        q.push(w);
        if (w == rocks.size() - 1) return dist[w];
      }
    }
  }

  return -1;
}

int main() {
  int n;
  double d;
  while (cin >> n >> d) {
    Rocks rocks(n);
    for (auto& rock : rocks)
      cin >> rock.x >> rock.y >> rock.r;

    int res = BFS(rocks, d);
    if (res == -1) cout << "Xof!" << endl;
    else cout << res << endl;
  }
}
