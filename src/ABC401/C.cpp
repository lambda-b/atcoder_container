#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
constexpr ll MOD = 1e9;
using mint = static_modint<MOD>;

int main() {
  int n, k;
  cin >> n >> k;

  vector<mint> a(k, 1LL);
  mint s = k;
  for (int i = k; i < n; i++) {
    int j = i % k;
    mint t = a[j];
    a[j] = s;
    s += s - t;
  }

  mint ans = n < k ? 1 : s;
  cout << ans.val() << endl;

  return 0;
}
