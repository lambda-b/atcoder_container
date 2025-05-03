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

  int s = 0;
  for (int i = 0; i < n; i += 2) {
    s += a[i];
  }
  cout << s << endl;

  return 0;
}
