#include <atcoder/all>
#include <iostream>
#include <set>
#include <utility>

using namespace atcoder;
using namespace std;

using ll = long long;

bool isInRange(ll a, ll b, ll n) { return 0 < a && a <= n && 0 < b && b <= n; }

int main() {
  ll n, m;
  cin >> n >> m;

  set<pair<int, int>> points;
  for (ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    points.insert({a, b});

    if (isInRange(a + 2, b + 1, n)) {
      points.insert({a + 2, b + 1});
    }
    if (isInRange(a + 1, b + 2, n)) {
      points.insert({a + 1, b + 2});
    }
    if (isInRange(a - 1, b + 2, n)) {
      points.insert({a - 1, b + 2});
    }
    if (isInRange(a - 2, b + 1, n)) {
      points.insert({a - 2, b + 1});
    }
    if (isInRange(a - 2, b - 1, n)) {
      points.insert({a - 2, b - 1});
    }
    if (isInRange(a - 1, b - 2, n)) {
      points.insert({a - 1, b - 2});
    }
    if (isInRange(a + 1, b - 2, n)) {
      points.insert({a + 1, b - 2});
    }
    if (isInRange(a + 2, b - 1, n)) {
      points.insert({a + 2, b - 1});
    }
  }

  cout << n * n - points.size() << endl;

  return 0;
}
