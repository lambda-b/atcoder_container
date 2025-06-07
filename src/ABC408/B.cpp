#include <bits/stdc++.h>

#include <algorithm>
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

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int m = (int)a.size();
  cout << m << endl;
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;

  return 0;
}
