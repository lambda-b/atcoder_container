#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  double f = 0.0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 't') {
      int x = 1;
      for (int j = i + 1; j < n; j++) {
        if (s[j] == 't') {
          x += 1;
          if (j - i > 1) {
            f = max(f, (double)(x - 2) / (j - i - 1));
          }
        }
      }
    }
  }

  cout << fixed << setprecision(17) << f << endl;

  return 0;
}
