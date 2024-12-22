#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--;
  y--;

  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  string t;
  cin >> t;
  set<pair<int, int>> house;
  for (char d : t) {
    int xa = x;
    int ya = y;
    switch (d) {
      case 'U':
        xa -= 1;
        break;
      case 'D':
        xa += 1;
        break;
      case 'L':
        ya -= 1;
        break;
      case 'R':
        ya += 1;
        break;
    }
    if (xa < 0 || xa >= h || ya < 0 || ya >= w) {
      continue;
    }
    switch (s[xa][ya]) {
      case '@':
        house.insert({xa, ya});
      case '.':
        x = xa;
        y = ya;
        break;
      case '#':
        break;
    }
  }

  cout << x + 1 << " ";
  cout << y + 1 << " ";
  cout << house.size() << endl;

  return 0;
}
