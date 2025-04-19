#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;

  bool authn = false;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "login") {
      authn = true;
    }
    if (s == "logout") {
      authn = false;
    }
    if (s == "private" && !authn) {
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
