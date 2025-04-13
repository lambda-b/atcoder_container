#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int a;
  cin >> a;

  if (400 % a == 0) {
    cout << 400 / a << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
