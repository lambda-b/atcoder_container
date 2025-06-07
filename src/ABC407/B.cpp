#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int x, y;
  cin >> x >> y;

  int cnt = 0;
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i + j >= x || abs(i - j) >= y) {
        cnt++;
      }
    }
  }

  cout << fixed << setprecision(16);
  cout << static_cast<double>(cnt) / 36.0 << endl;

  return 0;
}
