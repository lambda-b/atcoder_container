#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

struct model {
  string path;
  int node;
};

list<pair<int, int>> ff(int i, int j, vector<string> &c) {
  int n = (int)c.size();

  map<char, vector<int>> m;
  for (int k = 0; k < n; k++) {
    char &ch = c[i][k];
    if (ch == '-') {
      continue;
    }
    m[ch].push_back(k);
  }
  list<pair<int, int>> s;
  for (int k = 0; k < n; k++) {
    char &ch = c[k][j];
    if (ch == '-') {
      continue;
    }
    auto &t = m[ch];
    for (auto l : t) {
      s.push_back({l, k});
    }
  }

  return s;
}

int main() {
  int n;
  cin >> n;
  vector<string> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  vector<vector<int>> a(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    a[i][i] = 0;
  }
  list<pair<int, int>> left;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (c[i][j] != '-' && a[i][j] == -1) {
        a[i][j] = 1;
      }
      if (a[i][j] == -1) {
        left.push_back({i, j});
      }
    }
  }

  vector<vector<int>> called(n, vector<int>(n, 0));

  vector<vector<list<pair<int, int>>>> ss(n, vector<list<pair<int, int>>>(n));
  for (auto p : left) {
    ss[p.first][p.second] = ff(p.first, p.second, c);
  }

  for (int i = 0; i < n; i++) {
    for (auto it = left.begin(); it != left.end();) {
      auto &tt = ss[it->first][it->second];
      bool flag = false;
      for (auto &p : tt) {
        int &v = a[p.first][p.second];
        if (v != -1) {
          int &u = a[it->first][it->second];
          if (u == -1) {
            u = v + 2;
          } else {
            u = min(u, v + 2);
          }
          flag = true;
        }
      }
      if (flag) {
        called[it->first][it->second] += 1;
      }
      // とりあえず二回より呼ばれた場合は除外していく
      if (called[it->first][it->second] > 2) {
        left.erase(it++);
      } else {
        it++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j != 0) {
        cout << " ";
      }
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}
