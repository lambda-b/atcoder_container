#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint998244353;

struct triple {
  int x1, x2, x3;
};

mint func(int x1, int x2, int x3, map<triple, mint>& memo) {
  if (x1 == 0 && x2 == 0 && x3 == 0) {
    return 1;
  }
  triple t = {x1, x2, x3};
  if (memo.count(t)) {
    return memo[t];
  }
  mint ans = 0;
  if (x1 > 0) {
    ans += func(x1 - 1, x2, x3, memo);
    if (x3 > 0) {
      // いや違うな。これだと一個先に3が来る情報が含まれていない。
      ans -= func(x1 - 1, x2, x3 - 1, memo);
    }
  }
  if (x2 > 0) {
    ans += func(x1, x2 - 1, x3, memo);
  }
  if (x3 > 0) {
    ans += func(x1, x2, x3 - 1, memo);
  }
  return memo[t] = ans;
}

int main() {
  int x1, x2, x3;
  cin >> x1 >> x2 >> x3;

  map<triple, mint> memo;
  cout << func(x1, x2, x3, memo).val() << endl;

  return 0;
}
