/// https://atcoder.jp/contests/past202104-open/tasks/past202104_m
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace atcoder;
using namespace std;

using ll = long long;

template <class S>
struct model {
  map<int, S> mp;
  map<S, ll> cnt;
  ll comb = 0LL;

  S get(int p) const {
    auto it = mp.upper_bound(p);
    return it == mp.end() ? 0LL : it->second;
  }

  void update(S x, ll val) {
    ll &k = cnt[x];
    comb -= k * (k - 1) / 2;
    k += val;
    comb += k * (k - 1) / 2;
  }

  void update(int l, int r, S x) {
    auto itl = mp.upper_bound(l);
    auto itr = mp.upper_bound(r);

    int comp = itl == mp.begin() ? 0 : prev(itl)->first;
    if (comp < l && itl->second != x) {
      // comp < l : 区間 [l, r) の左端が元の領域を部分的に含む場合
      // itl->second != x: 特に、更新対象が変更されているとき
      mp[l] = itl->second;
    }

    int pr = l;
    for (auto it = itl; it != itr;) {
      // [pr, it->first) 区間の値を削除処理
      update(it->second, pr - it->first);

      pr = it->first;
      mp.erase(it++);
    }
    if (itr != mp.end()) {
      // 右端のあまり分を削除処理
      update(itr->second, pr - r);
    }
    // [l, r) 区間をxに更新
    update(x, r - l);

    if (itr == mp.end() || itr->second != x) {
      // 更新対象が変更されているとき、更新処理を行う
      // itr == mp.end() は itr->second を安全に行うための処理
      mp[r] = x;
    }
  }
};

int main() {
  int n;
  cin >> n;

  model<ll> mdl;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    mdl.update(i, i + 1, a);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    ll x;
    cin >> l >> r >> x;
    l--;

    mdl.update(l, r, x);
    cout << mdl.comb << endl;
  }

  return 0;
}
