#include <atcoder/all>
#include <iostream>
#include <set>
#include <utility>

using namespace atcoder;
using namespace std;

constexpr int n = 8;

int main() {
  vector<string> board(n);
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  set<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '#') {
        for (int k = 0; k < n; k++) {
          a.insert({k, j});
          a.insert({i, k});
        }
      }
    }
  }

  cout << n * n - a.size() << endl;

  return 0;
}
