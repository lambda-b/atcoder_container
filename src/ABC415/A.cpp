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

  int y;
  cin >> y;
  for (auto &x : a) {
    if (x == y) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
