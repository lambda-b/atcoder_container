#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  if (s1 == "sick" && s2 == "sick") {
    cout << 1 << endl;
  } else if (s1 == "sick") {
    cout << 2 << endl;
  } else if (s2 == "sick") {
    cout << 3 << endl;
  } else {
    cout << 4 << endl;
  }

  return 0;
}
