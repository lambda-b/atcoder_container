#include <atcoder/all>
#include <iostream>

#include "atcoder/fenwicktree.hpp"

using namespace atcoder;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  fenwick_tree<long> a(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    a.add(i, num);
  }

  for (long i = 0; i < q; i++) {
    long t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      cout << a.sum(l, r) << endl;
      continue;
    }

    a.add(l, r);
  }

  return 0;
}
