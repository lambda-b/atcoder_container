#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;

  set<int> a;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    a.insert(v);
  }

  vector<int> b;
  for (int i = 1; i <= n; i++) {
    if (a.find(i) == a.end()) {
      b.push_back(i);
    }
  }

  cout << (int)b.size() << endl;
  for (int i = 0; i < (int)b.size(); i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << b[i];
  }
  cout << endl;

  return 0;
}
