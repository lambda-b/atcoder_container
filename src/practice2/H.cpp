#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  two_sat sat(n);

  vector<int> x(n);
  vector<int> y(n);

  for (int i = 0; i < n; i++) {
    cin >> x[i];
    cin >> y[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (abs(x[i] - x[j]) < d) {
        sat.add_clause(i, false, j, false);
      }

      if (abs(x[i] - y[j]) < d) {
        sat.add_clause(i, false, j, true);
      }

      if (abs(y[i] - x[j]) < d) {
        sat.add_clause(i, true, j, false);
      }

      if (abs(y[i] - y[j]) < d) {
        sat.add_clause(i, true, j, true);
      }
    }
  }

  string satisfiable = sat.satisfiable() ? "Yes" : "No";
  cout << satisfiable << endl;

  if (satisfiable == "Yes") {
    vector<bool> ans = sat.answer();
    for (int i = 0; i < n; i++) {
      int val = ans[i] ? x[i] : y[i];
      cout << val << endl;
    }
  }

  return 0;
}
