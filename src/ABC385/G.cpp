#include <bits/stdc++.h>

#include <atcoder/all>

#include "atcoder/modint.hpp"

using namespace std;
using namespace atcoder;

using mint = modint998244353;

template <int m>
bool operator<(const static_modint<m> &lhs, const static_modint<m> &rhs) {
  return lhs.val() < rhs.val();
}

template <int m>
ostream &operator<<(ostream &os, static_modint<m> v) {
  os << v.val();
  return os;
}

template <typename T>
class Polynomial {
  /** 係数 */
  vector<T> coef;

 public:  //
  Polynomial(const vector<T> &coef) : coef(coef) {}

  Polynomial operator*(const Polynomial &other) const {
    vector<T> res = convolution(this->coef, other.coef);
    return Polynomial(res);
  }

  int deg() const {
    const int s = this->coef.size();
    return s - 1;
  }

  bool operator<(const Polynomial &other) const {
    if (this->deg() == other.deg()) {
      for (int i = this->deg(); i >= 0; i--) {
        if (this->coef[i] != other.coef[i]) {
          return this->coef[i] < other.coef[i];
        }
      }
    }
    return this->deg() < other.deg();
  }

  T &operator[](int i) { return coef[i]; }

  static Polynomial prod(set<Polynomial> &polys) {
    if (polys.empty()) {
      return Polynomial({1});
    }
    if (polys.size() == 1) {
      return *polys.begin();
    }
    auto first = polys.begin();
    auto second = next(first);
    Polynomial res = *first * *second;
    polys.erase(first);
    polys.erase(second);
    polys.insert(res);
    return prod(polys);
  }
};

/**
 * 挿入DPによる数え上げの問題
 * 形式的冪級数による高速化
 */
int main() {
  int n, k;
  cin >> n >> k;

  set<Polynomial<mint>> dp;
  for (int i = 0; i < n - 1; i++) {
    Polynomial<mint> p({1, i, 1});
    dp.insert(p);
  }

  Polynomial<mint> res = Polynomial<mint>::prod(dp);
  cout << res[n + k - 1] << endl;

  return 0;
}
