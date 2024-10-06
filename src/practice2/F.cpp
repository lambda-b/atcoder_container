#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

using mint = modint998244353;

int main() {
  int n, m;
  cin >> n >> m;

  vector<mint> a(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a[i] = tmp;
  }

  vector<mint> b(m);
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    b[i] = tmp;
  }

  int x = b[0].val();

  vector<mint> c = convolution(a, b);
  for (auto it = c.begin(); it != c.end(); it++) {
    if (it != c.begin()) {
      cout << " ";
    }
    cout << it->val();
  }

  cout << endl;

  return 0;
}
