#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  if (s == "red") {
    cout << "SSS" << endl;
  } else if (s == "blue") {
    cout << "FFF" << endl;
  } else if (s == "green") {
    cout << "MMM" << endl;
  } else {
    cout << "Unknown" << endl;
  }

  return 0;
}
