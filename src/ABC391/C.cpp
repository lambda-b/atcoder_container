#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;

  int cnt = 0;
  vector<int> pigeon(n), house(n, 1);
  iota(pigeon.begin(), pigeon.end(), 0);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, h;
      cin >> p >> h;
      p--;
      h--;

      if (house[pigeon[p]] == 2) {
        cnt -= 1;
      }
      house[pigeon[p]] -= 1;
      pigeon[p] = h;
      house[h] += 1;
      if (house[h] == 2) {
        cnt += 1;
      }
    } else {
      cout << cnt << endl;
    }
  }

  return 0;
}
