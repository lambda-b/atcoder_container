#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<set<int>> vec(n);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      vec[x].insert(y);
    }

    if (t == 2) {
      int x;
      cin >> x;
      x--;
      vec[x].insert(m);
    }

    if (t == 3) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      if (vec[x].find(m) != vec[x].end() || vec[x].find(y) != vec[x].end()) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}
