#include <atcoder/all>
#include <iostream>
#include <set>

using namespace atcoder;
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  string s;
  cin >> s;

  int cnt = 0;
  set<int> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '@') {
      cnt += 1;
      st.insert(i);
    }
  }

  int cnt2 = 0;
  string ans = "";
  for (int i = 0; i < n; i++) {
    if (st.count(i) == 1 && cnt2 + d < cnt) {
      cnt2 += 1;
      ans += "@";
    } else {
      ans += ".";
    }
  }

  cout << ans << endl;

  return 0;
}
