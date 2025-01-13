#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

set<int> eratosthenes(int n) {
  set<int> s;
  for (int i = 2; i <= n; i++) {
    s.insert(i);
  }
  for (auto it = s.begin(); *it * *it < n; it++) {
    for (auto t = next(it); t != s.end();) {
      if (*t % *it == 0) {
        s.erase(t++);
      } else {
        t++;
      }
    }
  }
  return s;
}

/**
 * ムズすぎる。後で答え見て実装する。
 */
int main() {
  int n;
  cin >> n;

  set<int> &&s = eratosthenes(500);
  for (auto v : s) {
    cout << v << endl;
  }

  return 0;
}
