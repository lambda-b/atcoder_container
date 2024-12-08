#include <bits/stdc++.h>

#include <algorithm>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;

  int volume = 0;
  int p_t = 0;
  for (int i = 0; i < n; i++) {
    int t, v;
    cin >> t >> v;

    volume = max(volume - (t - p_t), 0) + v;
    p_t = t;
  }
  cout << volume << endl;

  return 0;
}
