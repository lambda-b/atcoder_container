#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(q);
  for (auto &x : a) {
    cin >> x;
    x--;
  }

  int cnt = 0;
  vector<bool> box(n);
  for (auto &x : a) {
    bool left = x > 0 && box[x - 1];
    bool right = x < n - 1 && box[x + 1];
    int sign = box[x] ? 1 : -1;
    if (left && right) {
      cnt += sign * 1;
    }
    if (!left && !right) {
      cnt -= sign * 1;
    }
    box[x] = !box[x];
    cout << cnt << endl;
  }

  return 0;
}
