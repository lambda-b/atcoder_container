#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.size();

  vector<int> sa = suffix_array(s);
  vector<int> lcp = lcp_array(s, sa);

  long ans = s.substr(sa[0]).size();
  for (int i = 1; i < n; i++) {
    ans += s.substr(sa[i]).size() - lcp[i - 1];
  }

  cout << ans << endl;
  return 0;
}
