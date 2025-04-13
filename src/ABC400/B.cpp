#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace atcoder;

using bigint = boost::multiprecision::cpp_int;

using ll = long long;

int main() {
  bigint n;
  cin >> n;

  int m;
  cin >> m;

  bigint x = n == 1 ? (bigint)(m + 1) : (pow(n, m + 1) - 1) / (n - 1);
  bigint th = (bigint)pow(10, 9);
  if (x > th) {
    cout << "inf" << endl;
  } else {
    cout << x << endl;
  }

  return 0;
}
