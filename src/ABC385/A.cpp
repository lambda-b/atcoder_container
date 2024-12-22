#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a == b && b == c) {
    cout << "Yes" << endl;
    return 0;
  }

  if (a < b) {
    swap(a, b);
  }

  if (a < c) {
    swap(a, c);
  }

  if (a == b + c) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
