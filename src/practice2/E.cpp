#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n, k;

  cin >> n >> k;

  vector<vector<long>> a(n, vector<long>(n));
  long maximum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      maximum = max(maximum, a[i][j]);
    }
  }

  int start = 2 * n;
  int end = 2 * n + 1;
  mcf_graph<int, long> graph(2 * n + 2);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int from = i;
      int to = n + j;
      graph.add_edge(from, to, 1, maximum - a[i][j]);
    }

    graph.add_edge(start, i, k, 0);
    graph.add_edge(n + i, end, k, 0);
  }
  graph.add_edge(start, end, numeric_limits<int>::max(), maximum);

  auto pair = graph.flow(start, end, n * k);
  cout << n * k * maximum - pair.second << endl;

  vector<string> ans(n);
  fill(ans.begin(), ans.end(), string(n, '.'));

  auto edges = graph.edges();
  for (auto e = edges.begin(); e != edges.end(); e++) {
    if (e->flow == 0) {
      continue;
    }

    int from = e->from;
    int to = e->to;
    if (from == start || to == end) {
      continue;
    }

    int i = from;
    int j = to - n;

    ans[i][j] = 'X';
  }

  for (auto s = ans.begin(); s != ans.end(); s++) {
    cout << *s << endl;
  }

  return 0;
}
