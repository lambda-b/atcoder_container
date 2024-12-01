#include <atcoder/all>
#include <iostream>
#include <map>

using namespace atcoder;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  map<int, int> a;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    auto it = a.upper_bound(tmp);
    if (it == a.begin()) {
      a[tmp] = i;
    }
  }

  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;

    auto it = a.upper_bound(b);
    if (it == a.begin()) {
      cout << -1 << endl;
    } else {
      int eat = prev(it)->second;
      cout << eat + 1 << endl;
    }
  }

  return 0;
}
