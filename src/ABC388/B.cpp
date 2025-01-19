#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, d;
  cin >> n >> d;

  vector<pair<int, int>> snakes(n);
  for (int i = 0; i < n; i++) {
    int t, l;
    cin >> t >> l;
    snakes[i] = {t, l};
  }

  for (int k = 0; k < d; k++) {
    int m = 0;
    for (auto &s : snakes) {
      int w = s.first * (s.second + k + 1);
      m = max(w, m);
    }
    cout << m << endl;
  }

  return 0;
}
