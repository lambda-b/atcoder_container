#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;

  int half = (n + 1) / 2 - 1;
  string s = string(half, '-');
  cout << s;
  cout << '=';
  if (n % 2 == 0) {
    cout << '=';
  }
  cout << s << endl;

  return 0;
}
