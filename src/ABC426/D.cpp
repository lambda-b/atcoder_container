#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  int test_cases;
  cin >> test_cases;
  for (int _ = 0; _ < test_cases; _++) {
    int n;
    string s;
    cin >> n;
    cin >> s;

    // 最大の1の連続数
    int mcnt1 = 0;
    int cnt1 = 0;
    int w1 = 0;
    for (auto &c : s) {
      if (c == '1') {
        cnt1 += 1;
        mcnt1 = max(mcnt1, cnt1);
        w1 += 2;
      } else {
        cnt1 = 0;
        w1 += 1;
      }
    }
    w1 -= 2 * mcnt1;

    // 最大の0の連続数
    int mcnt0 = 0;
    int cnt0 = 0;
    int w0 = 0;
    for (auto &c : s) {
      if (c == '0') {
        cnt0 += 1;
        mcnt0 = max(mcnt0, cnt0);
        w0 += 2;
      } else {
        cnt0 = 0;
        w0 += 1;
      }
    }
    w0 -= 2 * mcnt0;

    cout << min(w0, w1) << endl;
  }

  return 0;
}
