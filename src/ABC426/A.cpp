#include <bits/stdc++.h>

#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

int version(string x) {
  if (x == "Ocelot") {
    return 0;
  }
  if (x == "Serval") {
    return 1;
  }
  return 2;
}

int main() {
  string x, y;
  cin >> x >> y;

  if (version(x) >= version(y)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
