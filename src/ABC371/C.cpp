#include <algorithm>
#include <atcoder/all>
#include <iostream>
#include <limits>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;

  int mg;
  cin >> mg;

  vector<set<int>> ug(n);
  for (int i = 0; i < mg; i++) {
    int u, v;
    cin >> u >> v;
    ug[u - 1].insert(v - 1);
    ug[v - 1].insert(u - 1);
  }

  int mh;
  cin >> mh;

  vector<set<int>> uh(n);
  for (int i = 0; i < mh; i++) {
    int a, b;
    cin >> a >> b;
    uh[a - 1].insert(b - 1);
    uh[b - 1].insert(a - 1);
  }

  vector<vector<int>> cost(n, vector<int>(n));
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> cost[i][j];
    }
  }

  vector<int> iso_map(n);
  iota(iso_map.begin(), iso_map.end(), 0);

  int mi = numeric_limits<int>::max();
  do {
    int c = 0;
    vector<int> inverse_map(n);
    for (int i = 0; i < n; i++) {
      inverse_map[iso_map[i]] = i;
    }
    for (int i = 0; i < n; i++) {
      set<int> mapped;
      for (auto e : ug[inverse_map[i]]) {
        mapped.insert(iso_map[e]);
      }

      set<int> symmetric;
      set_symmetric_difference(uh[i].begin(), uh[i].end(),             //
                               mapped.begin(), mapped.end(),           //
                               inserter(symmetric, symmetric.end()));  //
      for (auto e : symmetric) {
        if (i < e) {
          c += cost[i][e];
        } else {
          c += cost[e][i];
        }
      }
    }
    mi = min(mi, c / 2);  // 両向きの辺で二回勘定しているため x 1/2 しておく
  } while (next_permutation(iso_map.begin(), iso_map.end()));

  cout << mi << endl;

  return 0;
}
