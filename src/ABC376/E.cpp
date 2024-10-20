#include <algorithm>
#include <atcoder/all>
#include <iostream>
#include <limits>
#include <queue>

using namespace atcoder;
using namespace std;

using ll = long long;

struct model {
  ll a, b;
};

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    vector<model> mdl(n, {0, 0});
    for (int j = 0; j < n; j++) {
      cin >> mdl[j].a;
    }
    for (int j = 0; j < n; j++) {
      cin >> mdl[j].b;
    }
    sort(mdl.begin(), mdl.end(), [](model &l, model &r) { return l.a < r.a; });

    auto comp = [](model &l, model &r) { return l.b < r.b; };
    priority_queue<model, vector<model>, decltype(comp)> que(comp);

    ll s = 0;
    for (int j = 0; j < k - 1; j++) {
      s += mdl[j].b;
      que.push(mdl[j]);
    }

    ll ans = numeric_limits<ll>::max();
    for (int j = k - 1; j < n; j++) {
      ans = min(ans, (s + mdl[j].b) * mdl[j].a);

      s += mdl[j].b;
      que.push(mdl[j]);

      s -= que.top().b;
      que.pop();
    }

    cout << ans << endl;
  }

  return 0;
}
