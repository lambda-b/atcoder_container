#include <bits/stdc++.h>

#include <atcoder/all>
#include <iterator>

using namespace std;
using namespace atcoder;

using ll = long long;

template <typename T, typename U>
bool next_combination(const T &first, const T &last, const U &a_end) {
  auto rend = reverse_iterator(first);
  auto rbegin = reverse_iterator(last);
  if (next(*rbegin) != a_end) {
    (*rbegin)++;
    return true;
  }
  for (auto rit = next(rbegin); rit != rend; rit++) {
    if (next(*rit) != *prev(rit)) {
      (*rit)++;
      for (auto it = rit.base(); it != last; it++) {
        *it = next(*prev(it));
      }
      return true;
    }
  }
  return false;
}

/**
 * Runtime Error が解消できない。
 */
int main() {
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll s = 0;
  if (k > n / 2) {
    k = n - k;
    for (int i = 0; i < n; i++) {
      s ^= a[i];
    }
  }

  vector<decltype(a)::iterator> vec(k);
  for (int i = 0; i < k; i++) {
    vec[i] = a.begin() + i;
  }

  ll m = 0LL;
  do {
    ll t = s;
    for (auto it = vec.begin(); it != vec.end(); it++) {
      t ^= **it;
    }
    m = max(m, t);
  } while (next_combination(vec.begin(), vec.end(), a.end()));

  cout << m << endl;

  return 0;
}
