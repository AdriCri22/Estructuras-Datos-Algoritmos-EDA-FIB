#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<int, string> &a, const pair<int, string> &b) {
  if (a.first > b.first) return true;
  else if (a.first < b.first) return false;
  else {
    if (a.second < b.second) return true;
    else return false;
  }
}

int main() {
  string instr, player, player2;
  map<string, pair <int, bool> > scores;
  while (cin >> instr >> player) {
    auto it = scores.find(player);
    if (instr == "LOGIN") {
      if (it == scores.end())
        scores.insert(make_pair(player, make_pair(1200, true)));
      else it->second.second = true;
    }

    else if (instr == "LOGOUT") {
      if (it != scores.end()) it->second.second = false;
    }

    else if (instr == "PLAY") {
      cin >> player2;
      auto it2 = scores.find(player2);
      if (it != scores.end() and it->second.second == true
            and it2 != scores.end() and it2->second.second == true) {
        it->second.first += 10;
        if (it2->second.first > 1200) it2->second.first -= 10;
      } else cout << "player(s) not connected" << endl;
    }

    else if (instr == "GET_ELO") {
      if (it != scores.end())
        cout << player << ' ' << it->second.first << endl;
    }
  }
  cout << endl << "RANKING" << endl;
  vector<pair<int, string> > ranking;
  for (auto it = scores.begin(); it != scores.end(); it++) {
    ranking.push_back(make_pair(it->second.first, it->first));
  }

  sort(ranking.begin(), ranking.end(), comp);
  for (int i = 0; i < ranking.size(); i++) {
    cout << ranking[i].second << ' ' << ranking[i].first << endl;
  }
}
