#include <atcoder/all>
#include <iostream>
#include <map>

using namespace atcoder;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  map<int, int> mp;
  vector<int> nmb(n);
  for (int i = 0; i < n; i++) {
    mp[i + 1] = i;
    nmb[i] = 1;
  }

  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, c;
      cin >> x >> c;
      x--;
      c--;

      auto it = mp.upper_bound(x);
      int l = it == mp.begin() ? 0 : prev(it)->first;
      int r = it->first;
      nmb[it->second] -= r - l;
      nmb[c] += r - l;

      it->second = c;
      if (it != mp.begin()) {
        auto pre = prev(it);
        if (pre->second == c) {
          mp.erase(pre);
        }
      }
      auto nxt = next(it);
      if (nxt != mp.end()) {
        if (nxt->second == c) {
          mp.erase(it);
        }
      }
    }
    if (type == 2) {
      int c;
      cin >> c;
      c--;

      cout << nmb[c] << endl;
    }
  }

  return 0;
}
