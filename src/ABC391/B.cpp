#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> s(n), t(m);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }

  for (int a = 0; a < n - m + 1; a++) {
    for (int b = 0; b < n - m + 1; b++) {
      bool flag = true;
      for (int i = 0; i < m; i++) {
        string sub = s[i + a].substr(b, m);
        if (sub != t[i]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << a + 1 << " " << b + 1 << endl;
        return 0;
      }
    }
  }

  return 0;
}
