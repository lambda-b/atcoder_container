#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;

  vector<set<int>> device(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    set<int> &dev = device[i];

    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;

      dev.insert(a);
    }
  }

  int p, q;
  cin >> p >> q;
  vector<int> b(p);
  for (int i = 0; i < p; i++) {
    cin >> b[i];
  }

  int feasible = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    set<int> &dev = device[i];
    for (int nw : b) {
      if (dev.count(nw) > 0) {
        cnt += 1;
      }
    }
    if (cnt >= q) {
      feasible += 1;
    }
  }

  cout << feasible << endl;

  return 0;
}
