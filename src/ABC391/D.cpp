#include <bits/stdc++.h>

#include <atcoder/all>
#include <limits>

using namespace std;
using namespace atcoder;

using ll = long long;
using Pair = pair<int, ll>;

constexpr int INF = numeric_limits<int>::max();

int main() {
  int n, w;
  cin >> n >> w;

  vector<vector<Pair>> blocks(w);
  for (int i = 0; i < n; i++) {
    int x;
    ll y;
    cin >> x >> y;
    blocks[--x].push_back({i, y});
  }

  vector<int> orders(n);
  int size_min = INF;
  for (int i = 0; i < w; i++) {
    auto &bs = blocks[i];
    sort(bs.begin(), bs.end(), [](const auto &l, const auto &r) {  //
      return l.second < r.second;
    });
    for (int j = 0; j < (int)bs.size(); j++) {
      auto &b = bs[j];
      orders[b.first] = j;
    }
    size_min = min(size_min, (int)bs.size());
  }
  vector<ll> mxs(size_min);
  for (int i = 0; i < size_min; i++) {
    for (int j = 0; j < w; j++) {
      auto &bs = blocks[j];
      mxs[i] = max(mxs[i], bs[i].second);
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    ll t;
    int a;
    cin >> t >> a;
    a--;

    int o = orders[a];
    if (o < size_min) {
      ll height = mxs[o];
      if (height <= t) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    } else {
      cout << "Yes" << endl;
    }
  }

  return 0;
}
