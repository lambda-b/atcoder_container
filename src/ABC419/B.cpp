#include <bits/stdc++.h>

#include <atcoder/all>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
  int q;
  cin >> q;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      pq.push(x);
    }
    if (type == 2) {
      cout << pq.top() << endl;
      pq.pop();
    }
  }

  return 0;
}
