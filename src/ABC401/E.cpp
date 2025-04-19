#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

class Calc {
 public:
  void func(set<int> &connected, set<int> &unconnected, int i) {
    for (auto &e : g[i]) {
      connected.insert(e);
      if (e < p && unconnected.count(e) > 0) {
        unconnected.erase(e);
        func(connected, unconnected, e);
      }
    }
  }

  Calc(vector<vector<int>> &g, int p) : g(g), p(p) {}

 private:
  vector<vector<int>> &g;
  int p;
};

int main() {
  int n, m;
  cin >> n >> m;

  // ノードを増やしたタイミングで連結な要素は削除しなければならない
  // 1 → 2 → 3と増やしていった時の連結ノードを削除していく
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  set<int> connected = {0};
  set<int> unconnected;
  for (int i = 0; i < n; i++) {
    if (connected.count(i) == 0) {
      unconnected.insert(i);
      cout << -1 << endl;
      continue;
    }
    Calc calc{g, i};
    calc.func(connected, unconnected, i);
    if (unconnected.empty()) {
      int size = (int)connected.size();
      cout << size - i - 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
