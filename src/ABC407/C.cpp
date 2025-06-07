#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  s += '0';
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt++;

    int x = s[i] - '0';
    int y = s[i + 1] - '0';

    cnt += (10 + x - y) % 10;
  }

  cout << cnt << endl;

  return 0;
}
