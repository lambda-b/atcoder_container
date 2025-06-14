#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using Pair = pair<int, int>;

vector<Pair> func(vector<Pair> &vec) {
  if (vec.empty()) {
    return vector<Pair>();
  }
  sort(vec.rbegin(), vec.rend());
  vector<Pair> rtn{vec[0]};
  Pair base = vec[0];
  for (int i = 1; i < (int)vec.size(); i++) {
    if (vec[i].second > base.second) {
      rtn.push_back(vec[i]);
      base = vec[i];
    }
  }
  return rtn;
}

int main() {
  int n, h, m;
  cin >> n >> h >> m;

  vector<Pair> strategies{{h, m}};
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    vector<Pair> strategies0;
    for (auto &[hp, mp] : strategies) {
      if (hp >= a) {
        strategies0.push_back({hp - a, mp});
      }
      if (mp >= b) {
        strategies0.push_back({hp, mp - b});
      }
    }
    if (strategies0.empty()) {
      cout << i << endl;
      return 0;
    }
    strategies = func(strategies0);
  }

  cout << n << endl;

  return 0;
}
