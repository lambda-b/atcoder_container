#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;

  // boostによるUnion-Find木の実装
  dsu uf(n);
  vector<bool> blacks(n);
  map<int, int> cnt;

  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;

      int ul = uf.leader(u);
      int vl = uf.leader(v);
      if (ul == vl) {
        continue;
      }

      int p = cnt[ul];
      int q = cnt[vl];
      cnt.erase(ul);
      cnt.erase(vl);

      uf.merge(u, v);
      cnt[uf.leader(u)] = p + q;
    }
    if (type == 2) {
      int v;
      cin >> v;
      v--;

      cnt[uf.leader(v)] += blacks[v] ? -1 : 1;
      blacks[v] = !blacks[v];
    }
    if (type == 3) {
      int v;
      cin >> v;
      v--;

      if (cnt[uf.leader(v)] > 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}
