#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;

  vector<string> strs(n);
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
  }

  sort(strs.begin(), strs.end(),
       [](string a, string b) { return a.length() < b.length(); });  //

  string ans = "";
  for (auto s : strs) {
    ans += s;
  }
  cout << ans << endl;

  return 0;
}
