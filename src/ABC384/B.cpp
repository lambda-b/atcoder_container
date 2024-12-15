#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, r;
  cin >> n >> r;

  int t = r;
  for (int i = 0; i < n; i++) {
    int d, a;
    cin >> d >> a;
    if (d == 1) {
      if (1600 <= t && t < 2800) {
        t += a;
      }
    } else {
      if (1200 <= t && t < 2400) {
        t += a;
      }
    }
  }

  cout << t << endl;

  return 0;
}
