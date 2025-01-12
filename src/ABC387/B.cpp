#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int x;
  cin >> x;

  map<int, int> a;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      a[i * j] += 1;
    }
  }

  cout << 2025 - x * a[x] << endl;

  return 0;
}
