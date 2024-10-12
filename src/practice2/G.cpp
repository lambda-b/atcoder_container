#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  scc_graph graph(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(a, b);
  }

  vector<vector<int>> scc_groups = graph.scc();

  cout << scc_groups.size() << endl;
  for (auto it = scc_groups.begin(); it != scc_groups.end(); it++) {
    cout << it->size();
    for (auto i = it->begin(); i != it->end(); i++) {
      cout << " " << *i;
    }
    cout << endl;
  }
  return 0;
}
