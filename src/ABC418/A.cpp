#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n < 3) {
    cout << "No" << endl;
    return 0;
  }

  if (s.substr(n - 3, 3) == "tea") {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
