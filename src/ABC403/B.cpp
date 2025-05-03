#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string t, u;
  cin >> t >> u;

  int n = (int)t.size();
  int m = (int)u.size();

  bool judge = false;
  for (int i = 0; i < n - m + 1; i++) {
    bool judge0 = true;
    for (int j = 0; j < m; j++) {
      if (t[i + j] != '?' && t[i + j] != u[j]) {
        judge0 = false;
        break;
      }
    }
    judge = judge || judge0;
  }

  if (judge) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
