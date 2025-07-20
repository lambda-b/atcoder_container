#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  int p = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      if (p == -1) {
        p = i;
      } else {
        cout << p + 1 << "," << i + 1 << endl;
        p = -1;
      }
    }
  }

  return 0;
}
