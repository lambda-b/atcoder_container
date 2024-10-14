#include <algorithm>
#include <atcoder/all>
#include <cmath>
#include <iostream>

using namespace atcoder;
using namespace std;

using mint = modint1000000007;
using ll = long long;

struct b_mods {
  int b;

  ll n;

  vector<mint> mods;

  b_mods(int b, ll n, vector<mint> &mods) : b(b), n(n), mods(mods) {}

  mint &operator[](int i) { return mods[i]; }

  b_mods operator*(const b_mods &other) const {
    vector<mint> mods0(this->b);
    fill(mods0.begin(), mods0.end(), 0);

    ll n0 = this->n + other.n;
    modint::set_mod(b);
    modint tb = modint(10).pow(other.n);
    for (int i = 0; i < b; i++) {
      for (int j = 0; j < b; j++) {
        modint idx = tb * i + j;
        mods0[idx.val()] += this->mods[i] * other.mods[j];
      }
    }
    return b_mods(this->b, n0, mods0);
  }

  b_mods pow(const ll n) const {
    if (n == 1) return *this;
    b_mods a = pow(n / 2);
    if (n % 2 == 0) return a * a;
    return a * a * (*this);
  }
};

int main() {
  ll n;
  cin >> n;

  int b, k;
  cin >> b >> k;

  vector<mint> mods(b);
  fill(mods.begin(), mods.end(), 0);
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    mods[c % b] += 1;
  }
  b_mods base(b, 1, mods);

  b_mods ans = base.pow(n);
  cout << ans[0].val() << endl;

  return 0;
}
