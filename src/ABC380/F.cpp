#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

using ll = long long;

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  int k = n + m + l;

  vector<ll> a(n), b(m), c(l);
  vector<ll> x(k);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x[i] = a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    x[i + n] = b[i];
  }
  for (int i = 0; i < l; i++) {
    cin >> c[i];
    x[i + n + m] = c[i];
  }

  return 0;
}
