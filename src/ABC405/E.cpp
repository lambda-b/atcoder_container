#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

class Combination {
  vector<mint> facts;

 public:
  Combination(int n) : facts(n + 1) {
    facts[0] = 1;
    for (int i = 0; i < n; i++) {
      facts[i + 1] = facts[i] * (i + 1);
    }
  }

  mint operator()(int n, int r) {
    if (r < 0 || r > n) return 0;
    return facts[n] / (facts[r] * facts[n - r]);
  }
};

int main() {
  int apple, orange, banana, grape;
  cin >> apple >> orange >> banana >> grape;

  // constraints
  // apple -> banana
  // apple -> grape
  // orange -> grape

  mint cnt = 0;
  Combination comb(apple + orange + banana + grape);
  for (int i = 0; i <= orange; i++) {
    mint a_pattern = comb(apple + i, i) - comb(apple + i - 1, i - 1);
    mint b_pattern = comb(banana + grape + orange - i, banana);
    cnt += a_pattern * b_pattern;
  }

  cout << cnt.val() << endl;

  return 0;
}
