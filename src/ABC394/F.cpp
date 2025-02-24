#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using Graph = vector<vector<int>>;

pair<int, int> alkane(int vertex, int parent, Graph &g) {
  auto &adjacent = g[vertex];

  /* rootを持たない状態のパターン */
  int mm = -1;
  vector<int> s;
  for (auto &e : adjacent) {
    if (e == parent) {
      continue;
    }
    auto [a, b] = alkane(e, vertex, g);
    mm = max(mm, a + 1);
    mm = max(mm, b);
    s.push_back(a);
  }
  if ((int)adjacent.size() < 4) {
    return {1, mm};
  }
  int rtn = 1;
  sort(s.rbegin(), s.rend());
  for (int i = 0; i < 3; i++) {
    rtn += s[i];
  }
  if ((int)s.size() > 3) {
    mm = max(mm, rtn + s[3]);
  }
  return {rtn, mm};
}

int main() {
  int n;
  cin >> n;

  Graph graph(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  auto [_, mm] = alkane(0, n, graph);
  int ans = mm < 5 ? -1 : mm;
  cout << ans << endl;

  return 0;
}
