#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  string n;
  cin >> n;

  int one = count(n.begin(), n.end(), '1');
  int two = count(n.begin(), n.end(), '2');
  int three = count(n.begin(), n.end(), '3');

  if (one == 1 && two == 2 && three == 3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
