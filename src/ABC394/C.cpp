#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  for (auto it = s.rbegin(); it != prev(s.rend()); it++) {
    if (*it == 'A' && *next(it) == 'W') {
      *it = 'C';
      *next(it) = 'A';
    }
  }

  cout << s << endl;

  return 0;
}
