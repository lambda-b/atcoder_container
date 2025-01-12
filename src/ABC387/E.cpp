#include <bits/stdc++.h>

#include <atcoder/all>
#include <string>

using namespace std;
using namespace atcoder;

int main() {
  string n;
  cin >> n;

  int sz = n.size();

  if (sz < 5) {
    int x = stoi(n);
    int a = -1;
    for (int i = x; i < 2 * x; i++) {
      string s = to_string(i);
      int k = 0;
      for (auto c : s) {
        k += c - '0';
      }
      if (i % k == 0) {
        if (a + 1 == i) {
          cout << a << endl;
          return 0;
        }
        a = i;
      }
    }
    cout << -1 << endl;
    return 0;
  }

  switch (n[0]) {
    case '1':
      if (n[1] == '0') {
        cout << "11" << string(sz - 2, '0') << endl;
      } else {
        cout << "2" << string(sz - 1, '0') << endl;
      }
      break;
    case '2':
      cout << "35" << string(sz - 2, '0') << endl;
      break;
    case '3':
    case '4':
      cout << "53" << string(sz - 2, '0') << endl;
      break;
    case '5':
    case '6':
    case '7':
      cout << "8" << string(sz - 1, '0') << endl;
      break;
    case '8':
    case '9':
      cout << "11" << string(sz - 1, '0') << endl;
      break;
  }

  return 0;
}
