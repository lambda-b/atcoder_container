#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < n - 2; i++) {
    string sub = s.substr(i, 3);
    if (sub == "ABC") {
      cnt++;
    }
  }

  for (int i = 0; i < q; i++) {
    int x;
    char c;
    cin >> x >> c;
    x--;

    int t1 = s[x] - 'A';
    if (t1 < 3) {
      int p = max(x - t1, 0);
      int len = min(x - t1 + 3, 3);
      string sub1 = s.substr(p, len);
      if (sub1 == "ABC") {
        cnt--;
      }
    }

    s[x] = c;
    int t2 = c - 'A';
    if (t2 < 3) {
      int p = max(x - t2, 0);
      int len = min(x - t2 + 3, 3);
      string sub2 = s.substr(p, len);
      if (sub2 == "ABC") {
        cnt++;
      }
    }

    cout << cnt << endl;
  }

  return 0;
}
