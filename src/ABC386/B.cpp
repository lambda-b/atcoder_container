#include <bits/stdc++.h>

#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  int cnt = 0;
  for (auto it = s.begin(); it != s.end(); it++) {
    cnt++;
    if (*it != '0') {
      continue;
    }

    if (next(it) != s.end() && *next(it) == '0') {
      it++;
    }
  }

  cout << cnt << endl;

  return 0;
}
