#include <bits/stdc++.h>

#include <atcoder/all>
#include <iterator>
#include <memory>

using namespace std;
using namespace atcoder;

using ll = long long;

int sqrt_internal(int x, int k) {
  if (x * x <= k && (x + 1) * (x + 1) > k) {
    return x;
  }
  if (x * x > k) {
    return sqrt_internal(x / 2, k);
  }
  return sqrt_internal(x + x / 2, k);
}

int sqrt(int k) { return sqrt_internal(k / 2, k); }

/**
 * 座標圧縮クラス
 */
template <typename T>
class Compress {
  vector<T> values;

 public:  //
  Compress() = default;

  explicit Compress(vector<T> &v) : values(v) { compress(); }

  explicit Compress(vector<T> &&v) : values(move(v)) { compress(); }

  void compress() {
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
  }

  int index(T &x) {
    return lower_bound(values.begin(), values.end(), x) - values.begin();
  }

  T &value(int i) { return values[i]; }

  int size() { return values.size(); }
};

Compress<ll> compress;

/**
 * X,Y以下の数値の配置の状態を管理する
 */
class State {
 private:  //
  fenwick_tree<int> cnt;
  fenwick_tree<ll> sum;
  Compress<ll> &compress;

 public:  //
  State(Compress<ll> &compress) : compress(compress) {
    int n = compress.size();
    cnt = fenwick_tree<int>(n);
    sum = fenwick_tree<ll>(n);
  }

  int count(ll x) { return cnt.sum(0, compress.index(x) + 1); }

  ll summing(ll x) { return sum.sum(0, compress.index(x) + 1); }

  void plus(ll x, ll v) {
    int p = compress.index(x);
    cnt.add(p, 1);
    sum.add(p, v);
  }

  void minus(ll x, ll v) {
    int p = compress.index(x);
    cnt.add(p, -1);
    sum.add(p, -v);
  }
};

/**
 * vector
 */
vector<ll> a, b;

/**
 * fenwick_tree
 */
fenwick_tree<ll> a_tree, b_tree;

/**
 * クエリ
 */
class Query {
 public:  //
  int id;
  int x, y;
  ll value;
  int m;

  Query(int id, int x, int y, ll value, int m)
      : id(id), x(x), y(y), value(value), m(m) {}

  int block() const {
    assert(m != 0);
    return x / m;
  }

  bool operator<(const Query &other) const {
    if (block() != other.block()) {
      return block() < other.block();
    }
    if (y != other.y) {
      return y < other.y;
    }
    return id < other.id;
  }

  /**
   * クエリを更新する
   */
  ll solve(const Query &known, State &x_state, State &y_state) {
    value = known.value;
    ll bsum = b_tree.sum(0, known.y);
    for (int xi = known.x; xi < x; xi++) {
      ll va = a[xi];
      int c = y_state.count(va);
      ll s = y_state.summing(va);
      value += known.y * va + bsum - 2 * ((known.y - c) * va + s);
      x_state.plus(va, va);
    }

    for (int xi = known.x; xi > x; xi--) {
      ll va = a[xi - 1];
      int c = y_state.count(va);
      ll s = y_state.summing(va);
      value -= known.y * va + bsum - 2 * ((known.y - c) * va + s);
      x_state.minus(va, va);
    }

    ll asum = a_tree.sum(0, x);
    for (int yi = known.y; yi < y; yi++) {
      ll vb = b[yi];
      int c = x_state.count(vb);
      ll s = x_state.summing(vb);
      value += x * vb + asum - 2 * ((x - c) * vb + s);
      y_state.plus(vb, vb);
    }

    for (int yi = known.y; yi > y; yi--) {
      ll vb = b[yi - 1];
      int c = x_state.count(vb);
      ll s = x_state.summing(vb);
      value -= x * vb + asum - 2 * ((x - c) * vb + s);
      y_state.minus(vb, vb);
    }

    return value;
  }
};

/**
 * TLE解消できず。
 * アルゴリズムは回答通りなので、あとは定数倍の改善を図るしかない。
 */
int main() {
  int n;
  cin >> n;

  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<ll> s;
  copy(a.begin(), a.end(), back_inserter(s));
  copy(b.begin(), b.end(), back_inserter(s));
  Compress<ll> compress(s);

  a_tree = fenwick_tree<ll>(n);
  b_tree = fenwick_tree<ll>(n);
  for (int i = 0; i < n; i++) {
    a_tree.add(i, a[i]);
    b_tree.add(i, b[i]);
  }

  int k;
  cin >> k;
  vector<int> x(k), y(k);
  for (int i = 0; i < k; i++) {
    cin >> x[i] >> y[i];
  }

  int m = n / sqrt(k);
  State x_state(compress), y_state(compress);

  set<shared_ptr<Query>> queries;
  for (int i = 0; i < k; i++) {
    shared_ptr<Query> q = make_shared<Query>(Query(i, x[i], y[i], 0LL, m));
    queries.insert(q);
  }

  shared_ptr<Query> q0 = make_shared<Query>(Query(-1, 0, 0, 0LL, m));

  vector<ll> ans(k);
  for (auto q : queries) {
    ll v = q->solve(*q0, x_state, y_state);
    ans[q->id] = v;
    q0 = q;
  }

  for (auto v : ans) {
    cout << v << endl;
  }

  return 0;
}
