#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    int &k = mp[a[i]];
    if (k == 0) {
      k = i + 1;
    } else {
      k = -1;
    }
  }

  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    if (it->second > 0) {
      cout << it->second << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
