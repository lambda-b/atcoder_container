#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

class CartesianTree {
 public:
  CartesianTree(const vector<int>& a) : n((int)a.size()) { build(a); }

  int operator[](int i) const { return a[i].val; }
  int parent(int i) const { return a[i].parent; }
  int left(int i) const { return a[i].left; }
  int right(int i) const { return a[i].right; }

 private:
  struct Node {
    int val;
    int index;
    int parent;
    int left;
    int right;

    Node(int v, int index)
        : val(v), index(index), parent(-1), left(-1), right(-1) {}
  };
  int n;
  vector<Node> a;

  void build(const vector<int>& vals) {
    for (int i = 0; i < n; i++) {
      a.emplace_back(vals[i], i);
    }
    vector<int> stk;
    for (int i = 0; i < n; i++) {
      int last = -1;
      while (!stk.empty() && a[stk.back()].val > a[i].val) {
        last = stk.back();
        stk.pop_back();
      }
      if (!stk.empty()) {
        a[i].parent = stk.back();
        a[stk.back()].right = i;
      }
      if (last != -1) {
        a[last].parent = i;
        a[i].left = last;
      }
      stk.push_back(i);
    }
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  CartesianTree ct(a);
  for (int i = 0; i < n; i++) {
    cout << ct.parent(i);
    if (i < n - 1) {
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}
