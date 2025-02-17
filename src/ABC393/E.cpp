#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

vector<ll> eratosthenes(ll n) {
  list<ll> s;
  for (int i = 2; i <= n; i++) {
    s.push_back(i);
  }
  for (auto it = s.begin(); *it * *it < n; it++) {
    for (auto t = next(it); t != s.end();) {
      if (*t % *it == 0) {
        s.erase(t++);
      } else {
        t++;
      }
    }
  }
  vector<ll> vec;
  for (auto v : s) {
    vec.push_back(v);
  }
  return vec;
}

vector<ll> comb(vector<pair<ll, int>>::iterator first,
                vector<pair<ll, int>>::iterator last) {  //
  if (first == last) {
    return {1};
  }
  vector<ll> r = comb(next(first), last);
  auto pr = *first;
  vector<ll> rtn;
  ll k = 1;
  for (int i = 0; i <= pr.second; i++) {
    for (auto v : r) {
      rtn.push_back(v * k);
    }
    k *= pr.first;
  }
  return rtn;
}

vector<ll> divisors(ll v, vector<ll> &primes) {
  vector<pair<ll, int>> m;
  for (int i = 0; i < (int)primes.size() && primes[i] <= v; i++) {
    ll &p = primes[i];
    int cnt = 0;
    while (v % p == 0) {
      cnt += 1;
      v /= p;
    }
    if (cnt != 0) {
      m.push_back({p, cnt});
    }
  }
  vector<ll> d = comb(m.begin(), m.end());
  sort(d.begin(), d.end());
  return d;
}

/**
 * まだTLE
 */
int main() {
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  ll mx = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  vector<ll> primes = eratosthenes(mx);

  vector<set<int>> aaa(mx + 1);
  vector<vector<ll>> bbb(n);
  for (int i = 0; i < n; i++) {
    vector<ll> dvrs = divisors(a[i], primes);
    for (auto d : dvrs) {
      aaa[d].insert(i);
    }
    bbb[i] = dvrs;
  }

  for (int i = 0; i < n; i++) {
    vector<ll> &dvrs = bbb[i];
    for (auto r = dvrs.rbegin(); r != dvrs.rend(); r++) {
      if ((int)aaa[*r].size() >= k) {
        cout << *r << endl;
        break;
      }
    }
  }

  return 0;
}
