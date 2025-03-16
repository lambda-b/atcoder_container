#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  s = 'o' + s + 'i';

  int n = (int)s.size();
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      cnt += 1;
    }
  }
  cout << cnt << endl;

  return 0;
}
