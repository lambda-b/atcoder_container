#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

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
