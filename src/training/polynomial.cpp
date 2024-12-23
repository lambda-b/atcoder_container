#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

template <typename T>
class Polynomial {
  /** 係数 */
  vector<T> coef;

 public:  //
  Polynomial(const vector<T> &coef) : coef(coef) {}

  Polynomial operator+(const Polynomial &other) const {
    vector<T> res(max(coef.size(), other.coef.size()));
    for (int i = 0; i < res.size(); i++) {
      res[i] = (i < coef.size() ? coef[i] : 0) +
               (i < other.coef.size() ? other.coef[i] : 0);  //
    }
    return Polynomial(res);
  }

  Polynomial operator-() const {
    vector<T> res(coef.size());
    for (int i = 0; i < coef.size(); i++) {
      res[i] = -coef[i];
    }
    return Polynomial(res);
  }

  Polynomial operator-(const Polynomial &other) const {
    return *this + (-other);
  }

  Polynomial operator*(const Polynomial &other) const {
    vector<T> res = convolution(this->coef, other.coef);
    return Polynomial(res);
  }

  Polynomial operator<(const Polynomial &other) const {
    if (this->coef.size() != other.coef.size()) {
      return this->coef.size() < other.coef.size();
    }
    for (int i = this->coef.size() - 1; i >= 0; i--) {
      if (this->coef[i] != other.coef[i]) {
        return this->coef[i] < other.coef[i];
      }
    }
  }

  T &operator[](int i) const { return coef[i]; }

  static Polynomial prod(const set<Polynomial> &polys) {
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

int main() { return 0; }
