#include <atcoder/all>
#include <iostream>

#include "atcoder/math.hpp"

using namespace atcoder;
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    long n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << floor_sum(n, m, a, b) << endl;
  }

  return 0;
}
