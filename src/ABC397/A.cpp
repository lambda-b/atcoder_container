#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  double x;
  cin >> x;

  if (x >= 38.) {
    cout << 1 << endl;
  } else if (x >= 37.5) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }

  return 0;
}
