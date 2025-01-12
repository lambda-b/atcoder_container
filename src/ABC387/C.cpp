#include <bits/stdc++.h>

#include <atcoder/all>
#include <string>

using namespace std;
using namespace atcoder;

using ll = unsigned long long;

ll power(ll x, ll y) {
  if (y == 0) {
    return 1LL;
  }
  ll z = power(x, y / 2);
  return y % 2 == 0 ? z * z : z * z * x;
}

/**
 * val 未満のヘビ数の数え上げ
 */
ll func(ll val) {
  string v = to_string(val);
  ll vt = v[0] - '0';

  ll s = 0LL;
  // v が n 桁とするとき、n桁未満の対象のヘビ数の数え上げ
  for (ll i = 1LL; i < (ll)v.size(); i++) {
    for (ll j = 1LL; j < 10LL; j++) {
      s += power(j, i - 1);
    }
  }

  // 最大桁の数が vt 未満の n 桁のヘビ数の数え上げ
  for (ll i = 1LL; i < vt; i++) {
    s += power(i, v.size() - 1);
  }

  // 最大桁の数が vt の n 桁のヘビ数の数え上げ
  for (ll i = 1LL; i < (ll)v.size(); i++) {
    ll vv = v[i] - '0';
    if (vv < vt) {
      s += vv * power(vt, v.size() - i - 1);
    } else {
      s += power(vt, v.size() - i);
      break;
    }
  }

  return s;
}

int main() {
  ll l, r;
  cin >> l >> r;

  ll lv = func(l);
  ll rv = func(r + 1);
  cout << rv - lv << endl;

  return 0;
}
