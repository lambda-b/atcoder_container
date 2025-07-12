#include <bits/stdc++.h>

#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n;
  cin >> n;

  string s = "";
  for (int i = 0; i < n; i++) {
    char c;
    ll l;
    cin >> c >> l;
    if (l > 100) {
      cout << "Too Long" << endl;
      return 0;
    }

    s += string(l, c);
    if (s.size() > 100) {
      cout << "Too Long" << endl;
      return 0;
    }
  }
  cout << s << endl;
  return 0;
}
