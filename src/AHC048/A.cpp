#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

struct Color {
  double cyan, magenta, yellow;

  Color(double cyan, double magenta, double yellow)
      : cyan(cyan), magenta(magenta), yellow(yellow) {}
};

struct Paints {
  Color color;
  double weight;

  Paints operator+(const Paints other) const {
    double cyan = color.cyan * weight + other.color.cyan * other.weight;
    double magenta =
        color.magenta * weight + other.color.magenta * other.weight;
    double yellow = color.yellow * weight + other.color.yellow * other.weight;
    Color c{cyan, magenta, yellow};
    return Paints{c, weight};
  }

  double &get() { return weight; }
};

int main() {
  int n, k, h, t, d;
  cin >> n >> k >> h >> t >> d;

  Color color1{1., 1., 1.};

  Color color2{1, 1, 1};

  Paints p1{color1, 2.}, p2{color2, 1.};
  auto p3 = p1 + p2;

  Color c{1., 1., 1.};

  vector<int> a = {1, 2, 3};

  return 0;
}
