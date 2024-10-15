#include <algorithm>
#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a[i] = tmp - 1;
  }

  vector<vector<int>> s(n);
  for (int i = 0; i < n; i++) {
    s[a[i]].push_back(i);
  }

  ll summation = 0;
  ll alpha = 0;
  for (int i = 0; i < n; i++) {
    alpha += i + 1;
    vector<int> *si = &s[a[i]];
    auto it = lower_bound(si->begin(), si->end(), i);
    if (it != si->begin()) {
      --it;
      alpha -= *it + 1;
    }
    summation += alpha;
  }

  cout << summation << endl;

  return 0;
}
