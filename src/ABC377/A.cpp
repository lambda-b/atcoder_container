#include <atcoder/all>
#include <iostream>
#include <string>

using namespace atcoder;
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.size();

  if (n == 3 && s.find('A') < n && s.find('B') < n && s.find('C') < n) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
