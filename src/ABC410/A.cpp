#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (auto &x : a) {
    cin >> x;
  }

  int k;
  cin >> k;

  int cnt = 0;
  for (auto &x : a) {
    if (k <= x) {
      cnt += 1;
    }
  }

  cout << cnt << endl;

  return 0;
}
