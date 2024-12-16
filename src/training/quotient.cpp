#include <bits/stdc++.h>

#include <atcoder/all>
#include <iomanip>
#include <numeric>

using namespace std;
using namespace atcoder;

using ll = long long;

class Quotient {
  ll numerator, denominator;

 public:  //
  Quotient(const ll &numerator, const ll &denominator) {
    assert(denominator > 0);
    ll g = gcd(numerator, denominator);
    this->numerator = numerator / g;
    this->denominator = denominator / g;
  }

  Quotient(const ll &numerator) : Quotient(numerator, 1LL) {}

  Quotient operator+(const Quotient &other) const {
    ll n = this->numerator * other.denominator +
           this->denominator * other.numerator;
    ll d = this->denominator * other.denominator;
    return Quotient(n, d);
  }

  Quotient operator-() const { return Quotient(-numerator, denominator); }

  Quotient operator-(const Quotient &other) const { return *this + (-other); }

  Quotient operator*(const Quotient &other) const {
    ll n = this->numerator * other.numerator;
    ll d = this->denominator * other.denominator;
    return Quotient(n, d);
  }

  Quotient operator/(const Quotient &other) const {
    ll n = this->numerator * other.denominator;
    ll d = this->denominator * other.numerator;
    return Quotient(d > 0 ? n : -n, d > 0 ? d : -d);
  }

  Quotient operator=(const ll &rhs) const { return Quotient(rhs); }

  bool operator==(const Quotient &other) const {
    return this->numerator == other.numerator &&
           this->denominator == other.denominator;  //
  }

  double approximate() { return (double)numerator / denominator; }
};

ostream &operator<<(ostream &os, Quotient q) {
  os << fixed << setprecision(8);
  os << q.approximate();
  return os;
}

int main() {
  Quotient q1(-5, 2);
  Quotient q2 = 3;
  Quotient q3 = -q1;

  cout << q1 << endl;
  cout << q2 << endl;
  cout << q1 * q2 << endl;
  cout << q1 + q2 << endl;
  cout << q3 - q2 << endl;
  cout << q2 / q1 << endl;

  Quotient q4 = 10;
  Quotient q5 = 5;
  Quotient q6 = q5 / q4;
  cout << q4 / q5 << endl;
  if (q1 + q2 == q2 - q3) {
    cout << "Yes" << endl;
  }

  return 0;
}
