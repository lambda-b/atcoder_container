#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int func(set<int> &s) {
  int rtn = 0;
  for (auto it1 = s.begin(); it1 != s.end(); it1++) {
    rtn = max(1, rtn);
    for (auto it2 = next(it1); it2 != s.end(); it2++) {
      int w = *it2 - *it1;
      int m = 1;
      for (int i = 1; s.count(w * i + *it1) > 0; i++) {
        m += 1;
      }
      rtn = max(rtn, m);
    }
  }
  return rtn;
}

int main() {
  int n;
  cin >> n;

  int m = 0;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    m = max(h[i], m);
  }

  vector<set<int>> w(m);
  for (int i = 0; i < n; i++) {
    w[h[i] - 1].insert(i);
  }

  int ans = 0;
  for (set<int> &s : w) {
    int val = func(s);
    ans = max(val, ans);
  }

  cout << ans << endl;

  return 0;
}
