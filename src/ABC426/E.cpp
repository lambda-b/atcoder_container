#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

constexpr double INF = numeric_limits<double>::max();

struct Point {
  double x;
  double y;
};

double func(double a_x, double a_y, double b_x, double b_y) {
  return abs(a_x * b_y - a_y * b_x) / sqrt(a_x * a_x + a_y * a_y);
}

int main() {
  int test_cases;
  cin >> test_cases;
  for (int _ = 0; _ < test_cases; _++) {
    Point ts, tg, as, ag;
    cin >> ts.x >> ts.y >> tg.x >> tg.y;
    cin >> as.x >> as.y >> ag.x >> ag.y;

    double ans =
        sqrt((ts.x - as.x) * (ts.x - as.x) + (ts.y - as.y) * (ts.y - as.y));

    double td =
        sqrt((ts.x - tg.x) * (ts.x - tg.x) + (ts.y - tg.y) * (ts.y - tg.y));
    double ad =
        sqrt((as.x - ag.x) * (as.x - ag.x) + (as.y - ag.y) * (as.y - ag.y));
    if (td > ad) {
      swap(ts, as);
      swap(tg, ag);
      swap(td, ad);
    }

    double a_x0 = (tg.x - ts.x) / td - (ag.x - as.x) / ad;
    double a_y0 = (tg.y - ts.y) / td - (ag.y - as.y) / ad;
    double b_x0 = ts.x - as.x;
    double b_y0 = ts.y - as.y;

    double t0_min = -(a_x0 * b_x0 + a_y0 * b_y0) / (a_x0 * a_x0 + a_y0 * a_y0);
    if (0 <= t0_min && t0_min < td) {
      ans = min(ans, func(a_x0, a_y0, b_x0, b_y0));
    }

    Point am = {as.x + (ag.x - as.x) * td / ad, as.y + (ag.y - as.y) * td / ad};
    ans = min(ans, sqrt((tg.x - am.x) * (tg.x - am.x) +
                        (tg.y - am.y) * (tg.y - am.y)));

    double a_x1 = (ag.x - as.x) / ad;
    double b_x1 = as.x - tg.x;
    double a_y1 = (ag.y - as.y) / ad;
    double b_y1 = as.y - tg.y;

    double t1_min = -(a_x1 * b_x1 + a_y1 * b_y1) / (a_x1 * a_x1 + a_y1 * a_y1);
    if (td <= t1_min && t1_min < ad) {
      ans = min(ans, func(a_x1, a_y1, b_x1, b_y1));
    }

    ans = min(ans, sqrt((tg.x - ag.x) * (tg.x - ag.x) +
                        (tg.y - ag.y) * (tg.y - ag.y)));
    cout << fixed << setprecision(16) << ans << endl;
  }

  return 0;
}
