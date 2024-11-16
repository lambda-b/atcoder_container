#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  string s;
  cin >> s;

  string sub = s.substr(1, s.size() - 2);

  int cnt = 0;
  for (char c : sub) {
    if (c == '-') {
      cnt += 1;
    } else {
      cout << cnt << " ";
      cnt = 0;
    }
  }

  cout << cnt << endl;

  return 0;
}
