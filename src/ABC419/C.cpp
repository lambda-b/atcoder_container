#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> rows(n), cols(n);
  for (int i = 0; i < n; i++) {
    cin >> rows[i] >> cols[i];
  }

  ll mnr = *min_element(rows.begin(), rows.end());
  ll mxr = *max_element(rows.begin(), rows.end());
  ll mnc = *min_element(cols.begin(), cols.end());
  ll mxc = *max_element(cols.begin(), cols.end());

  ll r = (mxr - mnr + 1) / 2;
  ll c = (mxc - mnc + 1) / 2;

  cout << max(r, c) << endl;

  return 0;
}
