#include <bits/stdc++.h>

#include <atcoder/all>
#include <string>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  int n = s.size() / 4;
  string ans = "none";
  for (int i = 0; i < n; i++) {
    if (s[4 * i + 1] == 'o') {
      ans = to_string(i + 1);
    }
  }

  cout << ans << endl;

  return 0;
}
