#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  cout << s.substr(a, n - a - b) << endl;

  return 0;
}
