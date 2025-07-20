#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

class Service {
  int n;
  string &s;
  vector<int> cache;

 public:
  Service(int n, string &s) : n(n), s(s), cache((int)s.size(), -1) {
    // 最終行は確定
    cache.back() = 1;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == '1') {
        // 危険扱いのところは確定
        cache[i] = 0;
      }
    }
  }

  bool func(int k) {
    if (cache[k] != -1) {
      return cache[k] == 1;
    }
    int d = 1;
    for (int i = 0; i < n; i++) {
      if ((k & (1 << i)) == 0 && func(k + d)) {
        cache[k] = 1;
        return true;
      }
      d *= 2;
    }
    cache[k] = 0;
    return false;
  }
};

int main() {
  int test_case;
  cin >> test_case;

  for (int t = 0; t < test_case; t++) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    s = '0' + s;
    Service service(n, s);
    if (service.func(0)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
