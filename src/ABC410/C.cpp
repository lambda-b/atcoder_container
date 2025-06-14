#include <bits/stdc++.h>

#include <atcoder/all>
#include <numeric>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);

  ll head = 0;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      int index = (head + p) % n;
      a[index] = x;
    }

    if (t == 2) {
      int p;
      cin >> p;
      p--;
      int index = (head + p) % n;
      cout << a[index] << endl;
    }

    if (t == 3) {
      ll k;
      cin >> k;
      head += k;
      head %= n;
    }
  }

  return 0;
}
