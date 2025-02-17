#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  set<int> a, b, c;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'A') {
      a.insert(i);
    }
    if (s[i] == 'B') {
      b.insert(i);
    }
    if (s[i] == 'C') {
      c.insert(i);
    }
  }

  int cnt = 0;
  for (auto a1 : a) {
    auto f = b.upper_bound(a1);
    for (auto it = f; it != b.end(); it++) {
      int diff = *it - a1;
      int c1 = a1 + 2 * diff;
      if (c.find(c1) != c.end()) {
        cnt += 1;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}
