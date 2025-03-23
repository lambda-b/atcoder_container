#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

/**
 * 煙の座標からの相対座標を想定すれば解くことが可能
 */
int main() {
  int n, r, c;
  cin >> n >> r >> c;

  string s;
  cin >> s;

  pair<int, int> origin{0, 0}, person{r, c};
  set<pair<int, int>> smokes{{0, 0}};

  for (char &c : s) {
    if (c == 'N') {
      origin.first += 1;
      person.first += 1;
    }
    if (c == 'W') {
      origin.second += 1;
      person.second += 1;
    }
    if (c == 'S') {
      origin.first -= 1;
      person.first -= 1;
    }
    if (c == 'E') {
      origin.second -= 1;
      person.second -= 1;
    }
    smokes.insert({origin.first, origin.second});
    if (smokes.find(person) == smokes.end()) {
      cout << '0';
    } else {
      cout << '1';
    }
  }
  cout << endl;

  return 0;
}
