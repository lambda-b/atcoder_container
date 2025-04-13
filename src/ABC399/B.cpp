#include <bits/stdc++.h>

#include <atcoder/all>
#include <iterator>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[p[i]] += 1;
  }
  for (auto it = next(mp.rbegin()); it != mp.rend(); it++) {
    it->second += prev(it)->second;
  }

  for (int i = 0; i < n; i++) {
    auto it = mp.upper_bound(p[i]);
    if (it == mp.end()) {
      cout << 1 << endl;
    } else {
      cout << it->second + 1 << endl;
    }
  }

  return 0;
}
