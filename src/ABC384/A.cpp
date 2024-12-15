#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  char c1, c2;
  cin >> n >> c1 >> c2;
  string s;
  cin >> s;

  string ans = "";
  for (char c : s) {
    if (c == c1) {
      ans += c;
    } else {
      ans += c2;
    }
  }

  cout << ans << endl;

  return 0;
}
