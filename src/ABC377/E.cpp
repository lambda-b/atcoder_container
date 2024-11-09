#include <atcoder/all>
#include <iostream>
#include <set>

using namespace atcoder;
using namespace std;

using ll = long long;

struct power_of_2 {
  ll val;

  ll mod(ll p) {
    if (val == 0) {
      return 1LL;
    }
    power_of_2 other{val / 2};
    ll other_p = other.mod(p);
    ll other_p2 = other_p * other_p;
    if (val % 2 == 1) {
      return (other_p2 * 2) % p;
    }
    return other_p2 % p;
  }
};

/**
 * サイクル成分ごとに分解して考える
 *
 * この群は
 * a^{n-1} = 1 (mod n) とならないことに注意
 */
struct model {
  vector<vector<int>> cycles;

  int size;

  model(vector<int> &p) {
    size = p.size();
    set<int> counted;
    for (int i = 0; i < size; i++) {
      if (counted.count(p[i]) == 1) {
        continue;
      }
      vector<int> cycle;
      int a = p[i];
      do {
        cycle.push_back(a);
        counted.insert(a);
        a = p[a];
      } while (a != p[i]);
      cycles.push_back(cycle);
    }
  }

  vector<int> loop(int n) {
    vector<int> p(size);
    for (vector<int> &c : cycles) {
      int cs = c.size();
      int s = n % cs;
      for (int i = 0; i < cs; i++) {
        p[c[i]] = c[(i + s) % cs];
      }
    }
    return p;
  }

  vector<int> loop(power_of_2 &pow2) {
    vector<int> p(size);
    for (vector<int> &c : cycles) {
      int cs = c.size();
      int s = pow2.mod(cs);
      for (int i = 0; i < cs; i++) {
        p[c[i]] = c[(i + s) % cs];
      }
    }
    return p;
  }
};

int main() {
  int n;
  ll k;
  cin >> n >> k;

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    p[i] = tmp - 1;
  }

  power_of_2 pow2{k};
  model mdl(p);

  vector<int> rtn = mdl.loop(pow2);
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << rtn[i] + 1;
  }
  cout << endl;

  return 0;
}
