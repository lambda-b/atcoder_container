#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace atcoder;

using bigint = boost::multiprecision::cpp_int;

int main() {
  bigint n;
  cin >> n;

  bigint a = sqrt(n / 4);
  bigint b = sqrt(n / 2);

  cout << a + b << endl;

  return 0;
}
