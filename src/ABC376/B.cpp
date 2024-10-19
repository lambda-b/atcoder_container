#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  int operation = 0;

  int l = 0, r = 1;

  for (int i = 0; i < q; i++) {
    char h;
    int t;
    cin >> h >> t;
    t--;

    if (h == 'L') {
      int r0 = (n + r - l) % n;
      int t0 = (n + t - l) % n;
      if (r0 < t0) {
        operation += (n - t0) % n;
      } else {
        operation += t0;
      }
      l = t;
    } else {
      int l0 = (n + l - r) % n;
      int t0 = (n + t - r) % n;
      if (l0 < t0) {
        operation += (n - t0) % n;
      } else {
        operation += t0;
      }
      r = t;
    }
  }

  cout << operation << endl;

  return 0;
}
