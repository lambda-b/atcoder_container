#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  int bs = 0, cs = 0;
  vector<int> b(n, 0), c(n, 0);
  for (int i = 0; i < n; i++) {
    if (b[a[i]] == 0) {
      bs += 1;
    }
    b[a[i]] += 1;
  }

  int s = bs + cs;
  for (int i = 0; i < n; i++) {
    if (c[a[i]] == 0) {
      cs += 1;
    }
    b[a[i]] -= 1;
    c[a[i]] += 1;
    if (b[a[i]] == 0) {
      bs -= 1;
    }
    s = max(bs + cs, s);
  }

  cout << s << endl;

  return 0;
}
