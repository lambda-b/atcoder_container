#include <atcoder/all>
#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<set<int>> connect(n);

  for (int i = 0; i < n; i++) {
    connect[i].insert(i);
  }

  for (int i = 0; i < q; i++) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 1) {
      cout << connect[u].count(v) << endl;
      continue;
    }

    set<int> &bigger =
        connect[u].size() > connect[v].size() ? connect[u] : connect[v];
    set<int> &smaller =
        connect[u].size() > connect[v].size() ? connect[v] : connect[u];
    for (auto it = smaller.begin(); it != smaller.end(); it++) {
      connect[*it] = bigger;
      bigger.insert(*it);
    }
  }
}
