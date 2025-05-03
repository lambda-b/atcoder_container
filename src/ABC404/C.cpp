#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  set<int> visited;
  int current = 0;
  if (a[current].size() == 0) {
    cout << "No" << endl;
    return 0;
  }
  int prev = *a[current].begin();
  for (int i = 0; i < n; i++) {
    if (visited.find(current) != visited.end()) {
      cout << "No" << endl;
      return 0;
    }
    if (a[current].size() != 2) {
      cout << "No" << endl;
      return 0;
    }
    int tmp = current;
    current = a[current][0] == prev ? a[current][1] : a[current][0];
    prev = tmp;
    visited.insert(prev);
  }

  cout << "Yes" << endl;

  return 0;
}
