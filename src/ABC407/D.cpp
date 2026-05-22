#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

class Service {
  const vector<vector<ll>> a;
  const int h, w;

  vector<bool> painted;

  vector<ll> result;

 public:
  Service(const vector<vector<ll>> &a, const int h, const int w)
      : a(a), h(h), w(w), painted(h * w) {}

  void func(int target) {
    if (target == h * w - 1) {
      int ret = 0;
      for (int i = 0; i < h * w; i++) {
        if (!painted[i]) {
          int r = i / w;
          int c = i % w;
          ret ^= a[r][c];
        }
      }
      result.push_back(ret);
      return;
    }
    if (painted[target]) {
      func(target + 1);
      return;
    }
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

  int n = h * w;
  int m = n % 2 == 0 ? n / 2 : n / 2 + 1;

  return 0;
}
