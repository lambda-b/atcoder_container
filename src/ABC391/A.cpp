#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string d;
  cin >> d;

  for (auto &c : d) {
    switch (c) {
      case 'N':
        cout << 'S';
        break;
      case 'S':
        cout << 'N';
        break;
      case 'W':
        cout << 'E';
        break;
      case 'E':
        cout << 'W';
        break;
    }
  }
  cout << endl;

  return 0;
}
