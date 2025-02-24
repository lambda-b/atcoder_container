#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  int mx = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  /*
   * まずは各数字の個数を走査
   */
  vector<int> s(mx + 1, 0);
  for (int i = 0; i < n; i++) {
    s[a[i]] += 1;
  }

  /*
   * 各数字の倍数部分を足し合わせる
   */
  vector<int> t(mx + 1, 0);
  for (int i = 1; i <= mx; i++) {
    for (int j = i; j <= mx; j += i) {
      t[i] += s[j];
    }
  }

  /*
   * 個数について k 以上のものを記録していく
   */
  vector<int> u(mx + 1, 0);
  for (int i = 1; i <= mx; i++) {
    if (t[i] < k) {
      continue;
    }
    for (int j = i; j <= mx; j += i) {
      u[j] = max(u[j], i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << u[a[i]] << endl;
  }

  return 0;
}
