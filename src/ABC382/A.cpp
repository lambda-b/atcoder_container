#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  string s;
  cin >> s;

  int cnt = 0;
  for (char c : s) {
    if (c == '.') {
      cnt += 1;
    }
  }

  cout << cnt + d << endl;

  return 0;
}
