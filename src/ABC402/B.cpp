#include <bits/stdc++.h>

#include <atcoder/all>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
  int q;
  cin >> q;

  queue<int> a;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      a.push(x);
    } else {
      if (a.empty()) {
        cout << -1 << endl;
      } else {
        cout << a.front() << endl;
        a.pop();
      }
    }
  }

  return 0;
}
