#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;

  // Union-Find
  dsu uf(n);

  for (int i = 0; i < q; i++) {
    int type, u, v;
    cin >> type >> u >> v;

    if (type == 1) {
      cout << (uf.same(u, v) ? 1 : 0) << endl;
      continue;
    }

    uf.merge(u, v);
  }
}
