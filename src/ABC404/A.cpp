#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  for (char c = 'a'; c <= 'z'; c++) {
    if (s.find(c) == string::npos) {
      cout << c << endl;
      return 0;
    }
  }

  return 0;
}
