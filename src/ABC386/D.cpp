#include <bits/stdc++.h>

#include <atcoder/all>
#include <iterator>

using namespace std;
using namespace atcoder;

using ll = long long;

class Black {
  map<ll, ll> xmap;

 public:  //
  void register_black(const ll &x, ll &y) {
    auto itx = xmap.lower_bound(x);
    if (itx != xmap.end() && itx->second >= y) {
      return;
    }
    xmap[x] = y;
    auto start = reverse_iterator(xmap.lower_bound(x));
    for (auto it = start; it != xmap.rend();) {
      if (it->second > y) {
        return;
      }
      xmap.erase(it->first);
    }
  }

  bool judge_white(const ll &x, const ll &y) {
    auto itx = xmap.lower_bound(x);
    if (itx == xmap.end()) {
      return true;
    }
    return itx->second < y;
  }
};

class White {
  map<ll, ll> xmap;

 public:  //
  void register_white(const ll &x, ll &y) {
    auto itx = xmap.upper_bound(x);
    if (itx != xmap.begin() && reverse_iterator(itx)->second <= y) {
      return;
    }
    xmap[x] = y;
    auto start = xmap.upper_bound(x);
    for (auto it = start; it != xmap.end();) {
      if (it->second < y) {
        return;
      }
      xmap.erase(it++);
    }
  }

  bool judge_black(const ll &x, const ll &y) {
    auto itx = xmap.upper_bound(x);
    if (itx == xmap.begin()) {
      return true;
    }
    return reverse_iterator(itx)->second > y;
  }
};

int main() {
  ll n;
  int m;
  cin >> n >> m;

  Black black;
  White white;

  for (int i = 0; i < m; i++) {
    ll x, y;
    char c;
    cin >> x >> y >> c;

    if (c == 'B') {
      if (white.judge_black(x, y)) {
        black.register_black(x, y);
      } else {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (black.judge_white(x, y)) {
        white.register_white(x, y);
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}
