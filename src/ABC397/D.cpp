#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace atcoder;

using bigint = boost::multiprecision::cpp_int;

int main() {
  bigint n;
  cin >> n;

  for (bigint k = 1LL; k * k * k <= 4 * n; k += 1LL) {
    bigint d = k * (12 * n - 3 * k * k * k);
    if (d <= 0) {
      continue;
    }
    bigint sqd = sqrt(d);
    bigint y = (sqd - 3 * k * k) / (6 * k);
    bigint x = y + k;
    if (y <= 0) {
      continue;
    }
    bigint y3 = y * y * y;
    bigint x3 = x * x * x;
    if (x3 == y3 + n) {
      cout << x << " " << y << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
