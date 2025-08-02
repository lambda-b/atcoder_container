#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());

  for (auto bit = b.begin(); bit != b.end(); bit++) {
    for (auto ait = a.begin(); ait != a.end(); ait++) {
      if (*ait == *bit) {
        a.erase(ait);
        break;
      }
    }
  }
  for (int i = 0; i < (int)a.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;

  return 0;
}
