#include <bits/stdc++.h>

#include <atcoder/all>
#include <iomanip>

using namespace std;
using namespace atcoder;

using ld = long double;

int main() {
  int n;
  cin >> n;

  ld m = 0.;
  ld a = 0.;
  ld x0 = 0., h0 = 0.;
  bool viewed = true;
  for (int i = 0; i < n; i++) {
    ld x, h;
    cin >> x >> h;

    if (h > a * x + m) {
      a = (h - m) / x;
    } else {
      a = (h - h0) / (x - x0);
      m = (x * h0 - h * x0) / (x - x0);
      viewed = false;
    }
    x0 = x;
    h0 = h;
  }

  if (viewed) {
    cout << -1 << endl;
  } else {
    cout << fixed << setprecision(18);
    cout << m << endl;
  }

  return 0;
}
