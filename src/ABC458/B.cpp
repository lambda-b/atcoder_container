#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int h, w;
  cin >> h >> w;

  for (int i = 0; i < h; i++) {
    int result_i = 0;
    if (i == 0 && i == h - 1) {
      result_i = 0;
    } else if (i == 0 || i == h - 1) {
      result_i = 1;
    } else {
      result_i = 2;
    }
    for (int j = 0; j < w; j++) {
      int result_j = 0;
      if (j == 0 && j == w - 1) {
        result_j = 0;
      } else if (j == 0 || j == w - 1) {
        result_j = 1;
      } else {
        result_j = 2;
      }
      cout << result_i + result_j;
      if (j != w - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
