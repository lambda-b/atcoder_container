#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> a(n), b(n);
  vector<ll> c(m), d(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }

  map<ll, multiset<ll>> box_map;
  for (int i = 0; i < m; i++) {
    box_map[c[i]].insert(d[i]);
  }

  map<ll, vector<ll>> cmap;
  for (int i = 0; i < n; i++) {
    auto it = box_map.lower_bound(a[i]);
    if (it == box_map.end()) {
      cout << "No" << endl;
      return 0;
    }
    vector<ll> &vec = cmap[it->first];
    vec.push_back(b[i]);
  }

  multiset<ll> usable;
  for (auto rit = box_map.rbegin(); rit != box_map.rend(); rit++) {
    for (ll w : rit->second) {
      usable.insert(w);
    }
    auto vec = cmap[rit->first];
    for (ll w : vec) {
      auto it = usable.lower_bound(w);
      if (it == usable.end()) {
        cout << "No" << endl;
        return 0;
      }
      usable.erase(it);
    }
  }

  cout << "Yes" << endl;

  return 0;
}
