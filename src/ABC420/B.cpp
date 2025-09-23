#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<int> points(n);
  for (int i = 0; i < m; i++) {
    int k = n / 2;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == '1') {
        cnt += 1;
      }
    }
    char loser = cnt > k ? '1' : '0';
    for (int j = 0; j < n; j++) {
      points[j] += s[j][i] == loser ? 0 : 1;
    }
  }

  int mx = *max_element(points.begin(), points.end());
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (points[i] == mx) {
      if (flag) {
        cout << " ";
      } else {
        flag = true;
      }
      cout << i + 1;
    }
  }
  cout << endl;

  return 0;
}
