#include <bits/stdc++.h>

#include <atcoder/all>
#include <iterator>

using namespace std;
using namespace atcoder;

int main() {
  int q;
  cin >> q;

  set<string> x;
  multiset<string> y;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      string s;
      cin >> s;
      x.insert(s);

      auto it = y.lower_bound(s);
      while (it != y.end() && it->substr(0, (int)s.size()) == s) {
        y.erase(it++);
      }
    }

    if (t == 2) {
      string s;
      cin >> s;

      auto it = x.upper_bound(s);
      auto rit = reverse_iterator(it);
      if (rit == x.rend() || s.substr(0, (int)rit->size()) != *rit) {
        y.insert(s);
      }
    }

    cout << (int)y.size() << endl;
  }

  return 0;
}
