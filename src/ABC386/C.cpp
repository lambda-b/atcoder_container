#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int k;
  string s, t;
  cin >> k >> s >> t;

  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }

  if (s.size() == t.size()) {
    int cnt = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
      if (s[i] != t[i]) {
        if (cnt > 0) {
          cout << "No" << endl;
          return 0;
        }
        cnt++;
      }
    }
    cout << "Yes" << endl;
    return 0;
  }

  if (s.size() < t.size()) {
    swap(s, t);
  }

  int size = s.size();
  if (size != t.size() + 1) {
    cout << "No" << endl;
    return 0;
  }

  int cnt = 0;
  for (int i = 0; i < size; i++) {
    if (s[i + cnt] != t[i]) {
      if (cnt > 0) {
        cout << "No" << endl;
        return 0;
      }
      cnt++;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
