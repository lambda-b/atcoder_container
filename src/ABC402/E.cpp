#include <bits/stdc++.h>

#include <atcoder/all>
#include <bitset>

using namespace std;
using namespace atcoder;

struct model {
  int s;
  double prob;
  int cost;
};

double func(int x, bitset<8> ac, vector<model> &mdl,
            vector<vector<double>> &cache) {
  if (cache[ac.to_ulong()][x] > 0) {
    return cache[ac.to_ulong()][x];
  }
  double mx = 0;
  for (int i = 0; i < (int)mdl.size(); i++) {
    if (ac[i]) continue;
    auto &[s, prob, cost] = mdl[i];
    if (x - cost < 0) continue;
    ac[i] = true;
    double ok = func(x - cost, ac, mdl, cache);
    ac[i] = false;
    double ng = func(x - cost, ac, mdl, cache);
    mx = max(mx, prob * (s + ok) + (1 - prob) * ng);
  }

  cache[ac.to_ulong()][x] = mx;
  return mx;
}

int main() {
  int n, x;
  cin >> n >> x;

  vector<model> mdl(n);
  for (int i = 0; i < n; i++) {
    int s;
    double prob;
    int cost;
    cin >> s >> cost >> prob;
    prob /= 100;
    mdl[i] = {s, prob, cost};
  }

  vector<vector<double>> cache(pow(2, n), vector<double>(x + 1, -1));
  double ans = func(x, bitset<8>(0), mdl, cache);
  cout << fixed << setprecision(16) << ans << endl;

  return 0;
}
