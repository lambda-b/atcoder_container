#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  string ans = "";
  for (auto c : s) {
    if (c == '2') {
      ans += c;
    }
  }

  cout << ans << endl;

  return 0;
}
