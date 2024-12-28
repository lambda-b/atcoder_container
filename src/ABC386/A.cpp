#include <bits/stdc++.h>

#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  set<int> s;
  s.insert(a);
  s.insert(b);
  s.insert(c);
  s.insert(d);

  int x = s.size();
  if (x == 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
