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
      auto xit = x.lower_bound(s);
      auto rit = reverse_iterator(xit);
      if (rit == x.rend() || s.substr(0, (int)rit->size()) != *rit) {
        while (xit != x.end() && xit->substr(0, (int)s.size()) == s) {
          x.erase(xit++);
        }
        x.insert(s);
      }

      auto yit = y.lower_bound(s);
      while (yit != y.end() && yit->substr(0, (int)s.size()) == s) {
        y.erase(yit++);
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
