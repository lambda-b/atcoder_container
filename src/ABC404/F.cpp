#include <bits/stdc++.h>

#include <atcoder/all>
#include <cstdlib>

using namespace std;
using namespace atcoder;

class Strategy {
 private:
  int n;
  int m;

 public:
  vector<int> &s;
  vector<double> p;
  Strategy(int n, int m, vector<int> &s) : n(n), m(m), s(s) {
    p.resize(m + 1, 0);
    for (int i = 0; i < m; i++) {
      p[s[i]] += 1. / n;
    }
    p[0] = 1.;
    for (int i = 1; i <= m; i++) {
      p[0] -= p[i];
    }
  }
};

vector<vector<int>> divisions(int n, int k) {
  if (k == 1) {
    return {{n}};
  }
  vector<vector<int>> result;
  for (auto &x : divisions(n, k - 1)) {
    x.push_back(0);
    result.push_back(x);
  }
  if (n >= k) {
    for (auto &x : divisions(n - k, k)) {
      for_each(x.begin(), x.end(), [](int &v) { v++; });
      result.push_back(x);
    }
  }
  return result;
}

class Calculator {
 private:
  vector<Strategy> &strategies;
  vector<vector<double>> cache;

 public:
  Calculator(vector<Strategy> &strategies, int t, int k)
      : strategies(strategies) {
    cache.resize(t + 1, vector<double>(k + 1, -1));
  }

  double prob(int t, int k) {
    if (k <= 0) {
      return 1.;
    }
    if (t == 0) {
      return 0.;
    }
    if (cache[t][k] != -1) {
      return cache[t][k];
    }
    double pr = 0.;
    for (auto &s : strategies) {
      double p = 0.;
      for (int i = 0; i < (int)s.p.size(); i++) {
        p += s.p[i] * prob(t - 1, k - i);
      }
      pr = max(pr, p);
    }
    cache[t][k] = pr;
    return pr;
  }
};

/**
 * 分割数の計算
 */
int main() {
  int n, t, m, k;
  cin >> n >> t >> m >> k;

  vector<vector<int>> divs = divisions(min(n, m), m);
  vector<Strategy> strategies;
  for (int i = 0; i < (int)divs.size(); i++) {
    strategies.emplace_back(n, m, divs[i]);
  }

  Calculator calc(strategies, t, k);
  double ans = calc.prob(t, k);
  cout << fixed << setprecision(15) << ans << endl;

  return 0;
}
