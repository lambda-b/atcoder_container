#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

/**
 * 結局解けず...
 */
int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  map<char, char> mp;
  set<char> same;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      if (same.count(s[i]) || (mp.count(s[i]) && mp[s[i]] != t[i])) {
        cout << -1 << endl;
        return 0;
      }
      mp[s[i]] = t[i];
    } else {
      if (mp.count(s[i])) {
        cout << -1 << endl;
        return 0;
      }
      same.insert(s[i]);
    }
  }
  map<char, set<char>> rev;
  for (auto &x : mp) {
    if (rev.count(x.second) == 0) {
      rev[x.second] = set<char>();
    }
    rev[x.second].insert(x.first);
  }

  set<char> visited;
  int cnt = 0;
  for (auto &x : mp) {
    if (visited.count(x.first) == 0) {
      visited.insert(x.first);
      set<char> visited2;
      char ch = x.first;
      bool flag = rev[ch].size() > 1;
      while (mp.count(ch) > 0) {
        ch = mp[ch];
        if (visited2.count(ch) > 0) {
          if (flag) {
            cnt++;
          }
          break;
        }
        visited.insert(ch);
        visited2.insert(ch);
        flag = flag || rev[ch].size() > 1;
      }
    }
  }

  cout << (int)mp.size() + cnt << endl;

  return 0;
}
