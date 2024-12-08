/// https://atcoder.jp/contests/past202104-open/tasks/past202104_a
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  regex re(R"(^\d{3}-\d{4}$)");

  if (regex_match(s, re)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
