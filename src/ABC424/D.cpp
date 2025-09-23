#include <bits/stdc++.h>

#include <atcoder/all>
#include <iostream>
#include <limits>
#include <string>

using namespace std;
using namespace atcoder;

constexpr int INF = numeric_limits<int>::max();

bool judge(int x, int y, int w) {
  for (int i = 1; i < w; i++) {
    int a00 = x >> (i - 1) & 1;
    int a01 = x >> i & 1;
    int a10 = y >> (i - 1) & 1;
    int a11 = y >> i & 1;
    if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int test_cases;
  cin >> test_cases;

  for (int _ = 0; _ < test_cases; _++) {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
      cin >> s[i];
    }

    int n = 1 << w;
    vector<vector<int>> a(h, vector<int>(n));
    vector<int> dp(n);

    string &t = s[0];
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      for (int k = 0; k < w; k++) {
        char c = (j >> k) & 1 ? '.' : '#';
        if (t[k] == '#' && c == '.') {
          cnt += 1;
        }
        if (t[k] == '.' && c == '#') {
          cnt = INF;
          break;
        }
      }
      dp[j] = cnt;
    }

    for (int i = 1; i < h; i++) {
      string &t = s[i];
      vector<int> dq(n, INF);
      for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int k = 0; k < w; k++) {
          char c = (j >> k) & 1 ? '.' : '#';
          if (t[k] == '#' && c == '.') {
            cnt += 1;
          }
          if (t[k] == '.' && c == '#') {
            cnt = INF;
            break;
          }
        }
        if (cnt == INF) {
          continue;
        }
        for (int k = 0; k < n; k++) {
          if (judge(j, k, w) && dp[k] != INF) {
            dq[j] = min(dq[j], dp[k] + cnt);
          }
        }
      }
      dp = dq;
    }
    int ans = *min_element(dp.begin(), dp.end());
    cout << ans << endl;
  }

  return 0;
}
