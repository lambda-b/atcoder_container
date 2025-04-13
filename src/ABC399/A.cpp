#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      cnt += 1;
    }
  }
  cout << cnt << endl;

  return 0;
}
