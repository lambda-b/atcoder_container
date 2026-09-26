#include <bits/stdc++.h>

#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace atcoder;

using namespace __gnu_pbds;

using ll = long long;
using ordered_set =
    tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag,
         tree_order_statistics_node_update>;  //

int main() {
  ll x;
  cin >> x;
  int q;
  cin >> q;

  ordered_set s;
  s.insert({x, 0});
  for (int i = 0; i < q; i++) {
    ll a, b;
    cin >> a >> b;
    s.insert({a, 2 * i + 1});
    s.insert({b, 2 * i + 2});

    cout << s.find_by_order(i + 1)->first << endl;
  }

  return 0;
}
