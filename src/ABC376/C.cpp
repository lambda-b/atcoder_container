#include <algorithm>
#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  vector<int> b(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  b[n - 1] = 0;
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());

  int c = 0;
  int p = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i - c]) {
      if (c == 1) {
        c = 2;
        p = -1;
        break;
      }
      c = 1;
      p = a[i];
    }
  }

  cout << p << endl;

  return 0;
}
