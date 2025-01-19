#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  fenwick_tree<int> tree(n);
  for (int i = 0; i < n; i++) {
    int given = tree.sum(i, n);
    int possession = given + a[i];
    int take = min(possession, n - 1 - i);

    tree.add(i + take, 1);
    if (i != 0) {
      cout << " ";
    }
    cout << possession - take;
  }
  cout << endl;

  return 0;
}
