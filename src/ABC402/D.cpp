#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  // bj - ai == bi - aj (mod n)
  vector<int> c(n);
  vector<pair<int, int>> s(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    s[i] = {a, b};
    c[(a + b) % n] += 1;
  }

  ll cnt = 0LL;
  for (auto &[a, b] : s) {
    cnt += m;
    cnt -= c[(a + b) % n];
  }

  cout << cnt / 2 << endl;

  return 0;
}
