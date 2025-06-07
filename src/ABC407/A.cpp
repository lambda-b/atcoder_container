#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int a, b;
  cin >> a >> b;

  int c = a / b;
  double d = static_cast<double>(a) / b;
  if (d - c < c - d + 1) {
    cout << c << endl;
  } else {
    cout << c + 1 << endl;
  }

  return 0;
}
