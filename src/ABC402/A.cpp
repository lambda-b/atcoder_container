#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  string t = "";
  for (char &c : s) {
    if ('A' <= c && c <= 'Z') {
      t += c;
    }
  }
  cout << t << endl;

  return 0;
}
