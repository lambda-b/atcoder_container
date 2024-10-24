#include <atcoder/all>
#include <iostream>
#include <set>

using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;

  vector<set<int> *> s(n);
  for (int i = 0; i < n; i++) {
    set<int> *a = new set<int>();
    a->insert(i);
    s[i] = a;
  }

  for (int i = 0; i < q; i++) {
    int t, u, v;
    cin >> t >> u >> v;

    if (s[u]->size() < s[v]->size()) {
      swap(u, v);
    }

    if (t == 1) {
      cout << s[v]->count(u) << endl;
      continue;
    }

    if (s[v]->count(u) > 0) {
      continue;
    }

    set<int> *c = s[v];
    for (auto e : *c) {
      s[u]->insert(e);
      s[e] = s[u];
    }
  }

  return 0;
}
