#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, l, r;
  cin >> n >> l >> r;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    if (x <= l && r <= y) {
      cnt += 1;
    }
  }

  cout << cnt << endl;

  return 0;
}
