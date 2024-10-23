#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  string s;
  cin >> s;

  string ans = "";
  for (char c : s) {
    if (c == '.') {
      continue;
    }
    ans += c;
  }

  cout << ans << endl;

  return 0;
}
