#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  map<char, int> mp;
  for (auto &c : s) {
    mp[c] += 1;
  }

  for (auto &[k, v] : mp) {
    if (v == 1) {
      cout << k << endl;
      return 0;
    }
  }

  return 0;
}
