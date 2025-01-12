#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

using Graph = vector<vector<int>>;

vector<mint> func(Graph &tree, int node, int m) {
  vector<mint> rtn(m, mint(1));
  for (auto &v : tree[node]) {
    vector<mint> &&r = func(tree, v, m);
    for (int i = 0; i < m; i++) {
      rtn[i] *= r[i];
    }
  }
  for (int i = 1; i < m; i++) {
    rtn[i] += rtn[i - 1];
  }
  return rtn;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a[i] = v - 1;
  }

  scc_graph graph(n);
  for (int i = 0; i < n; i++) {
    graph.add_edge(i, a[i]);
  }

  auto &&result = graph.scc();
  vector<int> p(n);
  for (int i = 0; i < (int)result.size(); i++) {
    for (auto &v : result[i]) {
      p[v] = i;
    }
  }

  Graph tree(result.size());
  vector<int> roots;
  for (int i = 0; i < (int)result.size(); i++) {
    if ((int)result[i].size() == 1) {
      int to = p[a[result[i][0]]];
      if (to == i) {
        roots.push_back(i);
      } else {
        tree[to].push_back(i);
      }
    } else {
      roots.push_back(i);
    }
  }

  mint ans = mint(1);
  for (auto &r : roots) {
    vector<mint> &&vec = func(tree, r, m);
    ans *= vec[m - 1];
  }

  cout << ans.val() << endl;

  return 0;
}
