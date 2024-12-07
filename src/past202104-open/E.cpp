#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

void process(vector<int> &f, vector<int> &l, int x) {
  int full = f.size() + l.size();
  if (full < x) {
    cout << "ERROR" << endl;
  } else {
    int f_size = f.size();
    if (f_size < x) {
      int id = x - f_size - 1;
      cout << l[id] << endl;
      l.erase(l.begin() + id);
    } else {
      int id = f_size - x;
      cout << f[id] << endl;
      f.erase(f.begin() + id);
    }
  }
}

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> af, al;
  for (int i = 0; i < n; i++) {
    switch (s[i]) {
      case 'L':
        af.push_back(i + 1);
        break;
      case 'R':
        al.push_back(i + 1);
        break;
      case 'A':
        process(af, al, 1);
        break;
      case 'B':
        process(af, al, 2);
        break;
      case 'C':
        process(af, al, 3);
        break;
      case 'D':
        process(al, af, 1);
        break;
      case 'E':
        process(al, af, 2);
        break;
      case 'F':
        process(al, af, 3);
        break;
    }
  }

  return 0;
}
