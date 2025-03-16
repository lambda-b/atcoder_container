#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace atcoder;

using bigint = boost::multiprecision::cpp_int;

int main() {
  int n = 1000;
  for (int i = 0; i < n; i++) {
    bigint x = i;
    cout << x << ", " << sqrt(x) << endl;
  }

  return 0;
}
