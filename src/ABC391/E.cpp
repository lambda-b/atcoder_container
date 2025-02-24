#include <bits/stdc++.h>

#include <atcoder/all>
#include <exception>

using namespace std;
using namespace atcoder;

using Pair = pair<char, int>;

Pair func(string str) {
  int n = (int)str.size();
  if (n == 1) {
    return {str[0], 1};
  }
  int k = n / 3;
  auto [a0, a1] = func(str.substr(0, k));
  auto [b0, b1] = func(str.substr(k, k));
  auto [c0, c1] = func(str.substr(2 * k, k));

  if (a0 == b0 && b0 == c0) {
    if (a1 > b1) {
      swap(a1, b1);
    }
    if (b1 > c1) {
      swap(b1, c1);
    }
    return {a0, a1 + b1};
  }
  if (a0 == b0) {
    return {a0, min(a1, b1)};
  }
  if (b0 == c0) {
    return {b0, min(b1, c1)};
  }
  if (c0 == a0) {
    return {c0, min(c1, a1)};
  }
  throw exception();
}

int main() {
  int n;
  cin >> n;
  string a;
  cin >> a;

  auto [_, c] = func(a);
  cout << c << endl;

  return 0;
}
