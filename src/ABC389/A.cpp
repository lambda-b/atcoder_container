#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  int a = s[0] - '0';
  int b = s[2] - '0';

  cout << a * b << endl;

  return 0;
}
