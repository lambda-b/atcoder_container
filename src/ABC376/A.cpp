#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n, c;
  cin >> n >> c;

  int cnt = 0;
  int pre = -c;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t >= pre + c) {
      cnt += 1;
      pre = t;
    }
  }

  cout << cnt << endl;

  return 0;
}
