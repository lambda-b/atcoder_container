#include <bits/stdc++.h>

using namespace std;

struct Reference {
  int pc = -1;
  int layer = -1;
  int commit = -1;
};

struct Layer {
  Reference ref;
  vector<string> commits;

  Layer(Reference ref) : ref(ref), commits(0){};

  void push(string s) { commits.push_back(s); }

  string &operator[](int i) { return commits[i]; }

  int size() { return commits.size(); }
};

void output(Reference ref, vector<vector<Layer>> &pc) {
  if (ref.pc == -1) {
    return;
  }
  Layer layer = pc[ref.pc][ref.layer];
  output(layer.ref, pc);
  for (int i = 0; i < ref.commit; i++) {
    cout << layer[i];
  }
}

int main() {
  int n, q;
  cin >> n >> q;

  Reference server{-1, -1, -1};
  vector<vector<Layer>> pc(n, vector<Layer>(1, {{-1, -1, -1}}));
  for (int i = 0; i < q; i++) {
    int type, p;
    cin >> type >> p;
    p--;
    if (type == 1) {
      Layer layer(server);
      pc[p].push_back(layer);
    }
    if (type == 2) {
      string s;
      cin >> s;
      pc[p].back().push(s);
    }
    if (type == 3) {
      int layer = (int)pc[p].size() - 1;
      int commit = (int)pc[p][layer].size();
      server = {p, layer, commit};
    }
  }

  output(server, pc);
  cout << endl;

  return 0;
}
