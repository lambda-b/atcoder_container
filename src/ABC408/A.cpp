#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> t(n + 1);
  t[0] = 0;  // Start time is always 0
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }

  for (int i = 1; i <= n; i++) {
    if (t[i] - t[i - 1] > s) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
