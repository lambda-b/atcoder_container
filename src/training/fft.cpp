#include <bits/stdc++.h>

#include <chrono>
#include <random>

#include "atcoder/modint.hpp"

using namespace std;
using namespace atcoder;
using mint = modint998244353;

template <typename T>
class fft {
 public:  //
  /**
   * constructor
   * @param w 回転子
   * @param s サイズ
   */
  fft(T w, int s) : w(w), s(s) {
    T p = pow(w, s);
    assert(abs(p - 1.) < 1e-8);
  }

  /**
   * 計算を実行する
   * @param x 元の多項式
   * @return Fourier変換の計算結果
   */
  vector<T> calc(const vector<T> &x) const {
    assert(x.size() <= s);
    if (s == 1) {
      vector<T> y(1, 0);
      for (int i = 0; i < x.size(); i++) {
        y[i] = x[i];
      }
      return y;
    }

    vector<T> even(s / 2, 0), odd(s / 2, 0);
    T wi = 1;
    for (int i = 0; i < x.size(); i++) {
      even[i % (s / 2)] += x[i];
      odd[i % (s / 2)] += wi * x[i];
      wi *= w;
    }
    fft<T> f(w * w, s / 2);
    vector<T> ye = f.calc(even);
    vector<T> yo = f.calc(odd);
    vector<T> y(s);
    for (int i = 0; i < s / 2; i++) {
      y[2 * i] = ye[i];
      y[2 * i + 1] = yo[i];
    }
    return y;
  }

  /**
   * 愚直に計算した場合のFourier変換
   */
  vector<T> calc_silly(const vector<T> &x) const {
    vector<T> y(s, 0);
    T a = 1;
    for (int i = 0; i < s; i++) {
      T wi = 1;
      for (int j = 0; j < x.size(); j++) {
        y[i] += wi * x[j];
        wi *= a;
      }
      a *= w;
    }
    return y;
  }

 private:  //
  T w;
  int s;

  /**
   * 指数計算
   */
  static T pow(T v, int k) {
    if (k == 1) {
      return v;
    }
    T u = pow(v, k / 2);
    return k % 2 == 0 ? u * u : u * u * v;
  }

  static double abs(mint v) { return v.val(); }

  static double abs(complex<double> v) { return std::abs(v); }
};

/** 円周率 */
constexpr double pi = 3.14159265358979;

/**
 * 処理時間計算
 */
template <typename T>
double clock(T func) {
  auto start = chrono::system_clock::now();
  func();
  auto end = chrono::system_clock::now();
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int main() {
  random_device seed_gen;
  mt19937 engine(seed_gen());
  uniform_int_distribution<int> dist(0, 10);
  using fft_type = mint;

  int s = pow(2, 15);
  double cos = std::cos(2.0 * pi / s);
  double sin = std::sin(2.0 * pi / s);
  fft_type unit = mint(3).pow(119).pow(pow(2, 8));
  fft<fft_type> f(unit, s);

  int n = 10000;
  vector<fft_type> x(n);
  for (auto &v : x) {
    v = dist(engine);
  }

  // 愚直計算との計算速度の差を確認
  vector<fft_type> y;
  double elapsed_y = clock([&]() { y = f.calc(x); });
  cout << "y_time = " << elapsed_y << "[ms]" << endl;

  vector<fft_type> z;
  double elapsed_z = clock([&]() { z = f.calc_silly(x); });
  cout << "z_time = " << elapsed_z << "[ms]" << endl;

  // 愚直計算と値が一致していることを確認
  double norm = 0.;
  for (int i = 0; i < s; i++) {
    mint diff = y[i] - z[i];
    norm += diff.val();
  }
  cout << "norm = " << norm << endl;

  // 逆Fourier変換の確認
  fft<fft_type> f_inv(1 / unit, s);
  vector<fft_type> xy = f_inv.calc(y);
  double norm_inv = 0;
  for (int i = 0; i < x.size(); i++) {
    mint diff = x[i] - xy[i] / s;
    norm_inv += diff.val();
  }
  cout << "norm(inv) = " << norm_inv << endl;

  return 0;
}
