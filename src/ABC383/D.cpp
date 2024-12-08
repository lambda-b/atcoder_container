#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  ll n;
  cin >> n;

  ll l;
  for (ll x = 1; x * x <= n; x++) {
    l = x;
  }

  list<int> primes;
  for (int i = 2; i <= l; i++) {
    primes.push_back(i);
  }

  for (auto it = primes.begin(); it != primes.end(); it++) {
    for (auto p = next(it); p != primes.end();) {
      auto p2 = p++;
      if (*p2 % *it == 0) {
        primes.erase(p2);
      }
    }
    if (*it * *it > l) {
      break;
    }
  }

  ll ans = 0LL;
  for (auto it1 = primes.begin(); it1 != primes.end(); it1++) {
    for (auto it2 = next(it1); it2 != primes.end(); it2++) {
      if (*it1 * *it2 > l) {
        break;
      }
      ans += 1;
    }
    if (*it1 * *it1 > l) {
      break;
    }
  }

  for (auto p : primes) {
    if (p * p * p * p > l) {
      break;
    }
    ans += 1;
  }

  cout << ans << endl;

  return 0;
}
