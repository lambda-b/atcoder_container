#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    if (i < m) {
      cout << "OK" << endl;
    } else {
      cout << "Too Many Requests" << endl;
    }
  }

  return 0;
}
