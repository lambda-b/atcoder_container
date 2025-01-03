#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  set<int> a;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a.insert(v);
  }

  for (int i = 0; i < n + 1; i++) {
    if (a.count(i) == 0) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
