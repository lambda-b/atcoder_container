#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n, m, k;

  cin >> n >> m >> k;

  vector<int> l(n);
  vector<int> ans;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;

    a--;
    l[a] += 1;
    if (l[a] == m) {
      ans.push_back(a + 1);
    }
  }

  for (int i = 0; i < (int)ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
