#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

long summing(long l, long r) { return l + r; }
long unit() { return 0l; }

int main() {
  int n, q;
  cin >> n >> q;

  segtree<long, summing, unit> a(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    a.set(i, num);
  }

  for (long i = 0; i < q; i++) {
    long t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      cout << a.prod(l, r) << endl;
      continue;
    }

    a.set(l, r + a.get(l));
  }

  return 0;
}
