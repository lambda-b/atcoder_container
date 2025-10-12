#include <bits/stdc++.h>

#include <atcoder/all>
#include <string>

using namespace std;
using namespace atcoder;

int func(int n) {
  string s = to_string(n);
  int t = 0;
  for (char &c : s) {
    int i = c - '0';
    t += i;
  }
  return t;
}

int main() {
  int n;
  cin >> n;

  int a = 1;
  for (int i = 1; i < n; i++) {
    a += func(a);
  }
  cout << a << endl;

  return 0;
}
