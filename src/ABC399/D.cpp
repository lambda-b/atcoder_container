#include <bits/stdc++.h>

#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

int get_or_default(const vector<int> &a, int i, int default_value) {
  if (i < 0 || i >= (int)a.size()) {
    return default_value;
  }
  return a[i];
}

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto &x : a) {
      cin >> x;
      x--;
    }

    vector<pair<int, int>> b(n, {-1, -1});
    for (int i = 0; i < 2 * n; i++) {
      if (b[a[i]].first == -1) {
        b[a[i]].first = i;
      } else {
        b[a[i]].second = i;
      }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (abs(b[i].first - b[i].second) == 1) {
        continue;
      }
      int v1 = get_or_default(a, b[i].first - 1, -1);
      if (v1 > i) {
        int u1 = get_or_default(a, b[i].second - 1, -1);
        int u2 = get_or_default(a, b[i].second + 1, -1);
        if (u1 == v1 || u2 == v1) {
          cnt++;
        }
      }

      int v2 = get_or_default(a, b[i].first + 1, -1);
      if (v2 > i) {
        int u1 = get_or_default(a, b[i].second - 1, -1);
        int u2 = get_or_default(a, b[i].second + 1, -1);
        if (b[i].second - b[i].first > 3 && u1 == v2) {
          cnt++;
        }
        if (u2 == v2) {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
