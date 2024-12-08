#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<pair<int, int>> manhattan(int d) {
  vector<pair<int, int>> rtn;
  for (int i = -d; i <= d; i++) {
    for (int j = -d; j <= d; j++) {
      if (abs(i) + abs(j) <= d) {
        rtn.push_back({i, j});
      }
    }
  }

  return rtn;
}

int main() {
  int h, w, d;
  cin >> h >> w >> d;

  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  vector<pair<int, int>> manhattans = manhattan(d);

  int ans = 0;

  for (int i = 0; i < h * w; i++) {
    int ri = i / w;
    int ci = i % w;

    if (s[ri][ci] == '#') {
      continue;
    }

    for (int j = i + 1; j < h * w; j++) {
      int rj = j / w;
      int cj = j % w;

      if (s[rj][cj] == '#') {
        continue;
      }

      int target = 0;

      for (auto p : manhattans) {
        int rri = ri + p.first;
        int cci = ci + p.second;

        if (rri < 0 || rri >= h) {
          continue;
        }

        if (cci < 0 || cci >= w) {
          continue;
        }

        if (s[rri][cci] == '#') {
          continue;
        }

        if (abs(rri - rj) + abs(cci - cj) <= d) {
          continue;
        }

        target += 1;
      }

      for (auto p : manhattans) {
        int rrj = rj + p.first;
        int ccj = cj + p.second;

        if (rrj < 0 || rrj >= h) {
          continue;
        }

        if (ccj < 0 || ccj >= w) {
          continue;
        }

        if (s[rrj][ccj] == '#') {
          continue;
        }

        target += 1;
      }
      ans = max(target, ans);
    }
  }

  cout << ans << endl;

  return 0;
}
