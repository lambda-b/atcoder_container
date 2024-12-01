#include <atcoder/all>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace atcoder;
using namespace std;

string join(vector<int> &a) {
  ostringstream os;
  copy(a.begin(), a.end(), ostream_iterator<int>(os, " "));
  string s = os.str();
  return s.substr(0, s.size() - 1);
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  a[0] = 1;
  for (int i = 1; i < n; i++) {
    a[i] = a[i - 1] + 10;
  }

  vector<string> ans(0);
  ans.push_back(join(a));
  while (true) {
    bool terminated = true;
    for (auto it = a.rbegin(); it != a.rend(); it++) {
      auto comp = it == a.rbegin() ? m : *prev(it) - 10;
      if (*it < comp) {
        *it += 1;
        for (auto it1 = it.base(); it1 != a.end(); it1++) {
          *it1 = *prev(it1) + 10;
        }
        terminated = false;
        break;
      }
    }
    if (terminated) {
      break;
    }
    ans.push_back(join(a));
  }

  cout << ans.size() << endl;
  for (string s : ans) {
    cout << s << endl;
  }

  return 0;
}
