#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

class Plan {
 public:
  vector<int> a;
  ll total;

  Plan(vector<ll> cost, vector<int> a) : a(a) {
    ll total_cost = 0;
    for (int i = 0; i < (int)a.size(); i++) {
      total_cost += cost[i] * a[i];
    }
    this->total = total_cost;
  }

  bool operator<(const Plan &other) const { return total < other.total; }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> c(n);
  vector<vector<int>> a(m);

  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      x--;
      a[i].push_back(x);
    }
  }

  vector<Plan> plans;
  vector<int> current(n);
  while (true) {
    for (auto rit = current.rbegin(); rit != current.rend(); rit++) {
      if (*rit != 2) {
        (*rit)++;
        auto beg = rit.base();
        for (auto it = beg; it != current.end(); it++) {
          *it = 0;
        }
        break;
      }
    }

    Plan plan(c, current);
    plans.push_back(plan);

    bool all_two = true;
    for (int i = 0; i < n; i++) {
      if (current[i] != 2) {
        all_two = false;
        break;
      }
    }
    if (all_two) {
      break;
    }
  }

  sort(plans.begin(), plans.end());
  for (auto &plan : plans) {
    bool ok = true;
    for (auto &animal : a) {
      int cnt = 0;
      for (auto &x : animal) {
        cnt += plan.a[x];
      }
      if (cnt < 2) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << plan.total << endl;
      return 0;
    }
  }

  return 0;
}
