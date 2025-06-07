#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    char c = '_';
    int er = -1;
    for (int i = 1; i < n; i++) {
      if (c == '_') {
        if (s[i] < s[i - 1]) {
          c = s[i - 1];
          er = i - 1;
        }
      } else {
        if (c < s[i]) {
          auto it = s.begin() + i;
          s.insert(it, c);
          c = '!';
          break;
        }
      }
    }
    if (c != '_' && c != '!') {
      s.insert(s.end(), c);
    }

    if (er != -1) {
      s.erase(er, 1);
    }
    cout << s << endl;
  }

  return 0;
}
