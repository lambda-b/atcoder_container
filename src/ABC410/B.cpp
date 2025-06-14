#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> x(q);
  for (auto &v : x) {
    cin >> v;
  }

  vector<int> c(n);
  for (int j = 0; j < q; j++) {
    if (j > 0) {
      cout << " ";
    }
    int v = x[j];
    if (v > 0) {
      cout << v;
      c[v - 1] += 1;
    } else {
      int m = 0;
      for (int i = 1; i < n; i++) {
        if (c[m] > c[i]) {
          m = i;
        }
      }
      cout << m + 1;
      c[m] += 1;
    }
  }
  cout << endl;

  return 0;
}
