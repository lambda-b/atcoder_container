#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

struct Expr {
  int value;
  string expression;
  bool is_term;

  bool operator<(const Expr &other) const {
    if (value != other.value) {
      return value < other.value;
    }
    if (expression.size() != other.expression.size()) {
      return expression.size() < other.expression.size();
    }
    return expression < other.expression;
  }

  string to_string() const {
    if (is_term) {
      return expression;
    }
    return "(" + expression + ")";
  }
};

int main() {
  int n;
  cin >> n;

  vector<Expr> dp(n + 1);
  dp[0] = {0, "", true};
  for (int i = 1; i <= n; i++) {
    string a = to_string(i);
    if (all_of(a.begin(), a.end(), [](char c) { return c == '1'; })) {
      dp[i] = {i, a, true};
      continue;
    };
    dp[i] = {i, "1+" + dp[i - 1].expression, false};
    for (int j = 1; j < i - 1; j++) {
      if (i % j == 0) {
        int k = i / j;
        string sj = dp[j].to_string();
        string sk = dp[k].to_string();
        string si = sj + "*" + sk;
        dp[i] = min({i, si, true}, dp[i]);
      }
      string tj = dp[j].expression;
      string tk = dp[i - j].expression;
      string ti = tj + "+" + tk;
      dp[i] = min(dp[i], {i, ti, false});
    }
  }

  cout << dp[n].expression << endl;

  return 0;
}
