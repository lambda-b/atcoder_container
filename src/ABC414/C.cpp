#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;

string convert(const string str, const int n, const int m) {
  unsigned long sum = 0;
  for (char c : str) {
    sum = sum * n + (c - '0');
  }
  string res = "";
  do {
    int num = sum % m;
    res = static_cast<char>(num + '0') + res;
    sum /= m;
  } while (sum);
  return res;
}

bool judge(const string &s) {
  int n = (int)s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int a;
  ll n;
  cin >> a >> n;

  string a_str = to_string(n);
  int m = (int)a_str.size();
  int u = pow(10, m / 2);

  ll summing = 0;
  for (int j = 1; j < 10; j++) {
    char c = '0' + j;
    string s = string({c});
    string converted = convert(s, 10, a);
    ll num = stoll(s);
    if (num <= n && judge(converted)) {
      summing += num;
    }
  }

  for (int i = 1; i < u; i++) {
    string s0 = to_string(i);
    string sr = s0;
    reverse(sr.begin(), sr.end());
    string s = s0 + sr;
    string converted = convert(s, 10, a);
    ll num = stoll(s);
    if (num <= n && judge(converted)) {
      summing += num;
    }

    if ((int)s.size() == m) {
      continue;
    }
    for (int j = 0; j < 10; j++) {
      char c = '0' + j;
      string s = s0 + c + sr;
      string converted = convert(s, 10, a);
      ll num = stoll(s);
      if (num <= n && judge(converted)) {
        summing += num;
      }
    }
  }

  cout << summing << endl;

  return 0;
}
