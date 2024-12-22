#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using Graph = vector<vector<int>>;

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

  int snow_size = 0;
  for (int i = 0; i < n; i++) {
    vector<int> &nodes = graph[i];
    vector<int> y_vals(0);
    for (int v : nodes) {
      int yy = graph[v].size();
      y_vals.push_back(yy - 1);
    }
    sort(y_vals.begin(), y_vals.end());
    int s = y_vals.size();
    for (int j = 0; j < s; j++) {
      int x = s - j;
      int y = y_vals[j];
      int v = 1 + x + x * y;
      snow_size = max(v, snow_size);
    }
  }

  cout << n - snow_size << endl;

  return 0;
}
