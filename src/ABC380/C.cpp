#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  k--;

  string s;
  cin >> s;

  vector<pair<int, int>> vec;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (cnt == 0) {
        pair<int, int> p{i, 1};
        vec.push_back(p);
      } else {
        pair<int, int> p = *vec.rbegin();
        pair<int, int> q{p.first, cnt + 1};
        vec.pop_back();
        vec.push_back(q);
      }
      cnt++;
    } else {
      cnt = 0;
    }
  }

  pair<int, int> p0 = vec[k];
  pair<int, int> q0 = vec[k - 1];
  pair<int, int> r0{q0.first, q0.second + p0.second};
  vec[k - 1] = r0;
  vec.erase(vec.begin() + k);

  int pos = 0;
  for (auto p : vec) {
    string zeros = string(p.first - pos, '0');
    cout << zeros;

    string ones = string(p.second, '1');
    cout << ones;
    pos = p.first + p.second;
  }
  string end_zeros = string(n - pos, '0');
  cout << end_zeros << endl;

  return 0;
}
