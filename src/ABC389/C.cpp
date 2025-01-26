#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

struct Snake {
  ll point;
  ll length;
};

int main() {
  int q;
  cin >> q;

  int rm_num = 0;
  ll rm_point = 0LL;
  ll last_point = 0LL;

  vector<Snake> snakes;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      ll l;
      cin >> l;

      snakes.push_back({last_point, l});
      last_point += l;
    }

    if (t == 2) {
      Snake &snake = snakes[rm_num];
      rm_num += 1;
      rm_point += snake.length;
    }

    if (t == 3) {
      int k;
      cin >> k;
      k--;

      Snake &snake = snakes[k + rm_num];
      cout << snake.point - rm_point << endl;
    }
  }

  return 0;
}
