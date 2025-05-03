#include <bits/stdc++.h>

#include <atcoder/all>
#include <limits>

using namespace std;
using namespace atcoder;

constexpr int INF = numeric_limits<int>::max();

int main() {
  int n;
  cin >> n;

  vector<string> s(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  int mx = INF;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] != t[i][j]) {
        cnt++;
      }
    }
  }
  mx = min(mx, cnt);
  cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[n - j - 1][i] != t[i][j]) {
        cnt++;
      }
    }
  }
  mx = min(mx, cnt + 1);
  cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[n - i - 1][n - j - 1] != t[i][j]) {
        cnt++;
      }
    }
  }
  mx = min(mx, cnt + 2);
  cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[j][n - i - 1] != t[i][j]) {
        cnt++;
      }
    }
  }
  mx = min(mx, cnt + 3);

  cout << mx << endl;

  return 0;
}
