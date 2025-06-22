#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> d(n - 1);
  for (int i = 1; i < n; i++) {
    cin >> d[i - 1];
  }

  for (int i = 0; i < n - 1; i++) {
    int dd = 0;
    for (int j = i + 1; j < n; j++) {
      dd += d[j - 1];
      cout << dd;
      if (j != n - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
