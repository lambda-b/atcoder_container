#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

struct Grades {
  string name;

  int a, b, c, d, e;

  int sum() const { return a + b + c + d + e; }

  bool operator<(const Grades &other) const {
    int s1 = this->sum();
    int s2 = other.sum();
    if (s1 == s2) {
      return this->name < other.name;
    }
    return s1 > s2;
  }
};

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;

  set<Grades> members;
  for (int i = 1; i < 32; i++) {
    bitset<5> bit(i);
    string name = "";
    int aa = 0, bb = 0, cc = 0, dd = 0, ee = 0;
    if (bit[0]) {
      name += 'A';
      aa = a;
    }
    if (bit[1]) {
      name += 'B';
      bb = b;
    }
    if (bit[2]) {
      name += 'C';
      cc = c;
    }
    if (bit[3]) {
      name += 'D';
      dd = d;
    }
    if (bit[4]) {
      name += 'E';
      ee = e;
    }
    Grades grade{name, aa, bb, cc, dd, ee};
    members.insert(grade);
  }

  for (auto m : members) {
    cout << m.name << endl;
  }

  return 0;
}
