#include <bits/stdc++.h>

#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> whites(n, 0);
    vector<int> blacks(n, 0);
    if (s[0] == '1') {
      whites[0] = 1;
    } else {
      blacks[0] = 1;
    }
    for (int j = 1; j < n; j++) {
      int x = s[j] - '0';
      int y = 1 - x;
      whites[j] = whites[j - 1] + x;
      blacks[j] = blacks[j - 1] + y;
    }

    
  }

  return 0;
}
