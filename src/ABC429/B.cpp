#include <bits/stdc++.h>

#include <atcoder/all>
#include <numeric>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int s = accumulate(a.begin(), a.end(), 0);
  for (int i = 0; i < n; i++) {
    if (s - a[i] == m) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
