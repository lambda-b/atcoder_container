#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;

  vector<int> k(n);
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    vector<int> v(k[i]);
    for (int j = 0; j < k[i]; j++) {
      int x;
      cin >> x;
      v[j] = x - 1;
    }
    a[i] = v;
  }

  vector<vector<double>> p(n);
  for (int i = 0; i < n; i++) {
    int m = 0;
    vector<int> &b = a[i];
    for (auto x : b) {
      m = max(m, x + 1);
    }
    vector<double> q(m, 0.);
    int &cnt = k[i];
    for (int j = 0; j < cnt; j++) {
      double x = (double)cnt;
      q[b[j]] += 1. / x;
    }
    p[i] = q;
  }

  double ans = 0.;
  for (int i = 0; i < n; i++) {
    vector<double> &q1 = p[i];
    for (int j = i + 1; j < n; j++) {
      vector<double> &q2 = p[j];
      double s = 0;
      int size = min((int)q1.size(), (int)q2.size());
      for (int l = 0; l < size; l++) {
        s += q1[l] * q2[l];
      }
      ans = max(ans, s);
    }
  }
  cout << fixed << setprecision(15);
  cout << ans << endl;

  return 0;
}
