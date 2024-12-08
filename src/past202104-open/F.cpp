/// https://atcoder.jp/contests/past202104-open/tasks/past202104_f
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

class Computer {
  ll load_time = 0LL;

  ll l, t, x;

 public:  //
  Computer(ll l, ll t, ll x) : l(l), t(t), x(x){};

  bool is_high(ll b) { return b >= l; }

  ll low_load_processing(ll a) {
    load_time = 0LL;
    return a;
  }

  ll high_load_processing(ll a) {
    if (a > t) {
      return -1LL;
    }

    if (a + load_time < t) {
      load_time += a;
      return a;
    }

    if (a + load_time == t) {
      load_time = 0LL;
      return a + x;
    }

    ll current = t - load_time + x;
    load_time = 0LL;
    return current + high_load_processing(a);
  }
};

class Task {
  ll a, b;

 public:  //
  Task(ll a, ll b) : a(a), b(b) {}

  ll execute(Computer &computer) {
    return computer.is_high(b)                     //
               ? computer.high_load_processing(a)  //
               : computer.low_load_processing(a);  //
  }
};

int main() {
  int n, l, t, x;
  cin >> n >> l >> t >> x;
  Computer computer(l, t, x);

  ll ans = 0LL;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    Task task(a, b);

    ll c = task.execute(computer);
    if (c < 0) {
      ans = -1LL;
      break;
    }
    ans += c;
  }

  if (ans < 0) {
    cout << "forever" << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
