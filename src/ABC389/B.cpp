#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  ll x;
  cin >> x;

  ll fact = 1LL;
  for (int i = 1; i < 10000; i++) {
    fact *= (ll)i;
    if (fact == x) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
