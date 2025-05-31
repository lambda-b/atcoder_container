#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

struct Segment {
  int l, r;

  bool operator<(const Segment& other) const {
    if (l == other.l) {
      return r < other.r;
    }
    return l < other.l;
  }
};

/**
 * 作成中
 */
int main() {
  int n, m;
  cin >> n >> m;

  vector<Segment> segments(m);
  for (int i = 0; i < m; i++) {
    cin >> segments[i].l >> segments[i].r;
  }

  int q;
  cin >> q;

  return 0;
}
