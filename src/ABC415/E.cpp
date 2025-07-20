#include <bits/stdc++.h>

#include <atcoder/all>
#include <limits>

using namespace std;
using namespace atcoder;

using ll = long long;
constexpr ll INF = numeric_limits<ll>::max();

struct Point {
  int x, y;

  bool operator<(const Point &other) const {
    if (x + y != other.x + other.y) {
      return x + y < other.x + other.y;
    }
    return x < other.x;
  }
};

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<ll>> a(h, vector<ll>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  vector<ll> p(h + w - 1);
  for (int i = 0; i < h + w - 1; i++) {
    cin >> p[i];
  }
  vector<Point> points;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      Point point{i, j};
      points.push_back(point);
    }
  }
  sort(points.rbegin(), points.rend());

  // dp[i][j]: スタート地点が(i, j)でゴールまで移動するときの必要最低所持金
  vector<vector<ll>> dp(h, vector<ll>(w));
  for (auto &[x, y] : points) {
    ll b = a[x][y] - p[x + y];
    ll dp1 = x < h - 1 ? dp[x + 1][y] : INF;
    ll dp2 = y < w - 1 ? dp[x][y + 1] : INF;

    ll v = min(dp1, dp2);
    dp[x][y] = max(0LL, (v == INF ? 0LL : v) - b);
  }

  cout << dp[0][0] << endl;

  return 0;
}
