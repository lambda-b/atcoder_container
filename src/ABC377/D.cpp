#include <algorithm>
#include <atcoder/all>
#include <iostream>
#include <limits>
#include <utility>

using namespace atcoder;
using namespace std;
using ll = long long;

int op(int lhs, int rhs) { return min(lhs, rhs); }

int e() { return numeric_limits<int>::max(); }

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> ranges(n);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    ranges[i] = {l, r};
  }
  sort(ranges.begin(), ranges.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs.first != rhs.first) {
      return lhs.first < rhs.first;
    }
    return lhs.second < rhs.second;
  });

  vector<int> lefts(n);
  segtree<int, op, e> tree(n);
  for (int i = 0; i < n; i++) {
    lefts[i] = ranges[i].first;
    tree.set(i, ranges[i].second);
  }

  ll total = 0;
  for (int i = 0; i <= m; i++) {
    auto it = lower_bound(lefts.begin(), lefts.end(), i);
    int idx = it - lefts.begin();
    int xms = min(tree.prod(idx, n), m);
    total += xms - i;
  }

  cout << total << endl;

  return 0;
}
