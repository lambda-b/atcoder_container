#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  vector<bool> b(m);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i] - 1;
    if (!b[x]) {
      cnt++;
    }
    b[x] = true;
    if (cnt == m) {
      cout << n - i << endl;
      return 0;
    }
  }

  cout << 0 << endl;
  return 0;
}
