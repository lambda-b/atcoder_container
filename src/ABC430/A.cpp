#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (c >= a) {
    if (d >= b) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  } else {
    cout << "No" << endl;
  }

  return 0;
}
