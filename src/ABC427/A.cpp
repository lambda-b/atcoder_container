#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();

  for (int i = 0; i < n; i++) {
    if (i != n / 2) {
      cout << s[i];
    }
  }
  cout << endl;

  return 0;
}
