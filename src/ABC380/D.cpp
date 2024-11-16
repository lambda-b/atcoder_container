#include <atcoder/all>
#include <cmath>
#include <iostream>

using namespace atcoder;
using namespace std;

using ll = long long;

ll digit2(ll a) {
  if (a == 1) {
    return 1LL;
  }
  return 2 * digit2(a / 2);
}

ll log_mod(ll a) {
  ll c = digit2(a);
  return a - c;
}

bool is_same_origin(ll a) {
  if (a == 0) {
    return true;
  }
  if (a == 1) {
    return false;
  }
  ll c = log_mod(a);
  return !is_same_origin(c);
}

char t_form(char c) {
  if ('A' <= c && c <= 'Z') {
    return (char)c + 32;
  } else {
    return (char)c - 32;
  }
}

int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    ll k;
    cin >> k;
    k--;

    if (i != 0) {
      cout << " ";
    }

    ll n = s.size();
    ll m = k / n;
    bool b = is_same_origin(m);

    int r = k % n;
    if (b) {
      cout << s[r];
    } else {
      cout << t_form(s[r]);
    }
  }

  cout << endl;

  return 0;
}
