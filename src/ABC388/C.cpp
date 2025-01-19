#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

struct rice_cake {
  int volume;
  int order;

  bool operator<(const rice_cake &other) const {
    if (volume != other.volume) {
      return volume < other.volume;
    }
    return order > other.order;
  }
};

int main() {
  int n;
  cin >> n;

  set<rice_cake> a;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;

    a.insert({v, n - i});
  }

  ll cnt = 0;
  for (auto &c : a) {
    auto it = a.lower_bound({2 * c.volume, n});
    if (it == a.end()) {
      break;
    }
    cnt += it->order;
  }

  cout << cnt << endl;

  return 0;
}
