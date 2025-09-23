#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

struct Group {
  vector<int> members;
  set<int> blacks;

  Group(int x) { members.push_back(x); }

  int size() const { return members.size(); }
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<shared_ptr<Group>> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = make_shared<Group>(i);
  }

  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;

      if (a[u] == a[v]) {
        continue;
      }
      if (a[u]->size() < a[v]->size()) {
        swap(u, v);
      }

      vector<int> members = a[v]->members;
      set<int> blacks = a[v]->blacks;
      for (auto &x : members) {
        a[x] = a[u];
        a[u]->members.push_back(x);
      }
      for (auto &x : blacks) {
        a[u]->blacks.insert(x);
      }
    }
    if (type == 2) {
      int v;
      cin >> v;
      v--;

      set<int> &blacks = a[v]->blacks;
      if (blacks.find(v) == blacks.end()) {
        blacks.insert(v);
      } else {
        blacks.erase(v);
      }
    }
    if (type == 3) {
      int v;
      cin >> v;
      v--;

      set<int> &blacks = a[v]->blacks;
      if (blacks.empty()) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    }
  }

  return 0;
}
