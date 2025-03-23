#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  vector<int> a(13, 0);
  for (int i = 0; i < 7; i++) {
    int v;
    cin >> v;
    a[v - 1]++;
  }

  int c1 = 0;
  for (int i = 0; i < 13; i++) {
    if (a[i] >= 3) {
      c1 += 1;
    }
  }

  int c2 = 0;
  for (int i = 0; i < 13; i++) {
    if (a[i] >= 2) {
      c2 += 1;
    }
  }

  if (c1 >= 1 && c2 >= 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
