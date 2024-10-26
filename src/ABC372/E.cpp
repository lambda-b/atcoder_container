#include <atcoder/all>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace atcoder;
using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;  //

/**
 * ordered_set を利用した問題
 */
int main() {
  int n, q;
  cin >> n >> q;

  vector<ordered_set *> a(n);
  for (int i = 0; i < n; i++) {
    ordered_set *b = new ordered_set();
    b->insert(i);
    a[i] = b;
  }

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;

    if (t == 2) {
      int v, k;
      cin >> v >> k;
      v--;

      int p = a[v]->size() - k;
      if (p < 0) {
        cout << -1 << endl;
      } else {
        auto it = a[v]->find_by_order(p);
        cout << *it + 1 << endl;
      }
      continue;
    }

    int u, v;
    cin >> u >> v;
    u--;
    v--;

    if (a[u] == a[v]) {
      continue;
    }

    if (a[u]->size() < a[v]->size()) {
      swap(u, v);
    }

    ordered_set &c = *a[v];
    for (auto e : c) {
      a[u]->insert(e);
      a[e] = a[u];
    }

    free(&c);
  }

  return 0;
}
