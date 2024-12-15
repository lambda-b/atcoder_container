#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = unsigned long long;

template <class T>
struct Node {
  int r, c;
  T w;

  bool operator<(const Node &other) const {
    if (this->w == other.w) {
      if (this->r == other.r) {
        return this->c < other.c;
      }
      return this->r < other.r;
    }
    return this->w < other.w;
  }
};

template <class T>
class Graph {
  int h, w;
  vector<vector<T>> val;

 public:  //
  Graph(int h, int w) {
    this->h = h;
    this->w = w;
    val = vector<vector<T>>(h, vector<T>(w, 0));
  }

  T &get(int r, int c) { return val[r][c]; }

  vector<Node<T>> adjacent(int r, int c) const {
    vector<Node<T>> l(0);
    if (r - 1 >= 0) {
      l.push_back({r - 1, c, val[r - 1][c]});
    }
    if (r + 1 < h) {
      l.push_back({r + 1, c, val[r + 1][c]});
    }
    if (c - 1 >= 0) {
      l.push_back({r, c - 1, val[r][c - 1]});
    }
    if (c + 1 < w) {
      l.push_back({r, c + 1, val[r][c + 1]});
    }
    return l;
  }
};

int main() {
  int h, w;
  ll x;
  cin >> h >> w >> x;

  int p, q;
  cin >> p >> q;
  p--;
  q--;

  Graph<ll> graph(h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      ll s;
      cin >> s;
      graph.get(i, j) = s;
    }
  }

  ll power = graph.get(p, q);
  set<Node<ll>> adjacent;
  for (Node<ll> a : graph.adjacent(p, q)) {
    adjacent.insert(a);
  }

  set<pair<int, int>> absorbed;
  absorbed.insert({p, q});
  while (adjacent.size() > 0) {
    auto weakest = adjacent.begin();
    double dw = weakest->w;
    double dp = power;
    if (weakest->w * x == power || dw > dp / x) {
      break;
    }

    int r = weakest->r;
    int c = weakest->c;
    power += weakest->w;
    absorbed.insert({r, c});
    adjacent.erase(weakest);
    for (Node<ll> a : graph.adjacent(r, c)) {
      if (absorbed.count({a.r, a.c}) == 0) {
        adjacent.insert(a);
      }
    }
  }

  cout << power << endl;

  return 0;
}
