#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    p[i] = v - 1;
  }
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    q[i] = v - 1;
  }

  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    s[q[i]] = q[p[i]];
  }

  for (int i = 0; i < n; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << s[i] + 1;
  }
  cout << endl;

  return 0;
}
