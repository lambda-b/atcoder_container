#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  ll sx, sy;
  cin >> sx >> sy;

  map<ll, set<ll>> x_points, y_points;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    x_points[x].insert(y);
    y_points[y].insert(x);
  }

  int cnt = 0;
  for (int i = 0; i < m; i++) {
    char d;
    ll c;
    cin >> d >> c;

    if (d == 'U') {
      set<ll> &s = x_points[sx];
      auto f = s.lower_bound(sy);
      auto l = s.upper_bound(sy + c);
      for (auto it = f; it != l;) {
        cnt += 1;
        y_points[*it].erase(sx);
        s.erase(it++);
      }
      sy += c;
    }

    if (d == 'D') {
      set<ll> &s = x_points[sx];
      auto f = s.lower_bound(sy - c);
      auto l = s.upper_bound(sy);
      for (auto it = f; it != l;) {
        cnt += 1;
        y_points[*it].erase(sx);
        s.erase(it++);
      }
      sy -= c;
    }

    if (d == 'L') {
      set<ll> &s = y_points[sy];
      auto f = s.lower_bound(sx - c);
      auto l = s.upper_bound(sx);
      for (auto it = f; it != l;) {
        cnt += 1;
        x_points[*it].erase(sy);
        s.erase(it++);
      }
      sx -= c;
    }

    if (d == 'R') {
      set<ll> &s = y_points[sy];
      auto f = s.lower_bound(sx);
      auto l = s.upper_bound(sx + c);
      for (auto it = f; it != l;) {
        cnt += 1;
        x_points[*it].erase(sy);
        s.erase(it++);
      }
      sx += c;
    }
  }

  cout << sx << " ";
  cout << sy << " ";
  cout << cnt << endl;

  return 0;
}
