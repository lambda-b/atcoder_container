#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int x, y;
  cin >> x >> y;
  cout << (x + y - 1) % 12 + 1 << endl;

  return 0;
}
