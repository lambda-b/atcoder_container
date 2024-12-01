#include <atcoder/all>
#include <iomanip>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<double> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i] = p[i] / 100.;
  }

  vector<double> prob(2, 0.);
  prob[0] = 1.;
  for (int i = 1; i <= n; i++) {
    vector<double> prob0(i + 1);
    prob0[0] = prob[0] * (1. - p[i - 1]);
    for (int j = 1; j <= i; j++) {
      prob0[j] = prob[j] * (1. - p[i - 1]) + prob[j - 1] * p[i - 1];
    }
    prob = prob0;
  }

  vector<double> expect(x + 1, 0.);
  for (int i = 1; i <= x; i++) {
    double ex = 1.;
    for (int j = 1; j <= n; j++) {
      ex += expect[max(i - j, 0)] * prob[j];
    }
    expect[i] = ex / (1. - prob[0]);
  }
  cout << fixed << setprecision(16);
  cout << expect[x] << endl;

  return 0;
}
