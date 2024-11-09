#include <atcoder/all>
#include <iostream>
#include <numeric>

using namespace atcoder;
using namespace std;

using ll = long long;

struct power_of_2 {
  ll val;

  ll mod(ll p) {
    if (val == 0) {
      return 1LL;
    }
    power_of_2 other{val / 2};
    ll other_p = other.mod(p);
    ll other_p2 = other_p * other_p;
    if (val % 2 == 1) {
      return (other_p2 * 2) % p;
    }
    return other_p2 % p;
  }
};

struct model {
  vector<int> perm;

  model(const vector<int> &perm) : perm(perm) {}

  model operator*(model &other) {
    int n = this->perm.size();
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
      perm[i] = this->perm[other.perm[i]];
    }
    return {perm};
  }

  model pow(ll k) {
    if (k == 0) {
      vector<int> perm(this->perm.size());
      iota(perm.begin(), perm.end(), 0);
      model m(perm);
      return m;
    }
    model a = this->pow(k / 2);
    if (k % 2 == 0) {
      return a * a;
    }
    return a * a * (*this);
  }

  int &operator[](int k) { return perm[k]; }
};

int main() {
  int n;
  ll k;
  cin >> n >> k;
  while (k >= n) {
    k = k / n + k % n;
  }

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    p[i] = tmp - 1;
  }

  power_of_2 pow2{k};
  ll q = pow2.mod(n - 1);
  model mdl(p);
  model rtn = mdl.pow(q);

  cout << q << endl;

  for (int i = 0; i < n; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << rtn[i] + 1;
  }
  cout << endl;
  cout << endl;

  model a = mdl;
  for (int i = 0; i < 29; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[j] + 1 << " ";
    }
    cout << endl;
    a = a * mdl;
  }

  return 0;
}
