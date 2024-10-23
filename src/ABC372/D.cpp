#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

using ll = long long;

int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int main() {
  int n;
  cin >> n;

  segtree<int, op, e> tree(n);
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    h--;
    tree.set(i, h);
  }

  vector<ll> cnt(n, 0LL);
  for (int i = n - 2; i >= 0; i--) {
    int h = tree.get(i + 1);
    int p = tree.max_right(i + 1, [h](int v) { return v <= h; });
    cnt[i] = cnt[p - 1] + 1;
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << cnt[i];
  }

  cout << endl;

  return 0;
}
