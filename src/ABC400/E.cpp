#include <bits/stdc++.h>

#include <algorithm>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
#include <iterator>

using namespace std;
using namespace atcoder;

using ll = long long;
using bigint = boost::multiprecision::cpp_int;

vector<ll> erathosthenes(int n) {
  list<ll> primes(n - 1);
  iota(primes.begin(), primes.end(), 2);
  for (auto it = primes.begin(); it != primes.end(); ++it) {
    if (*it * *it > n) break;
    for (auto jt = next(it); jt != primes.end();) {
      if (*jt % *it == 0) {
        jt = primes.erase(jt);
      } else {
        ++jt;
      }
    }
  }
  return vector<ll>(primes.begin(), primes.end());
}

set<ll> prime_factors_kind2(ll n) {
  vector<ll> counts(n + 1, 0);
  vector<ll> primes = erathosthenes(n);
  counts[0] = 1;
  counts[1] = 1;
  for (auto it = primes.begin(); it != primes.end(); ++it) {
    for (ll j = *it; j <= n; j += *it) {
      counts[j] += 1;
    }
  }

  set<ll> res;
  for (int i = 0; i < (int)counts.size(); i++) {
    if (counts[i] == 2) {
      res.insert(i);
    }
  }

  return res;
}

int main() {
  int q;
  cin >> q;

  vector<ll> a(q);
  ll mx = 0;
  for (int i = 0; i < q; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  ll mx_sqrt = (ll)sqrt((bigint)mx);
  set<ll> factors = prime_factors_kind2(mx_sqrt);

  for (auto &v : a) {
    ll sqrt_v = (ll)sqrt((bigint)v);
    auto it = factors.upper_bound(sqrt_v);
    ll sqrt_ans = *reverse_iterator(it);
    ll ans = sqrt_ans * sqrt_ans;
    cout << ans << endl;
  }

  return 0;
}
