#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

struct Edge {
  int index;
  int first, second;
};
struct ColorEdge : public Edge {
  bool visited;
};
using ColorEdgePtr = shared_ptr<ColorEdge>;
using Graph = vector<vector<ColorEdgePtr>>;

void dfs(int v, Graph &graph, vector<bool> &color,
         vector<Edge> &detachable) {  //
  auto &edges = graph[v];
  for (auto e : edges) {
    if (e->visited) {
      continue;
    }

    e->visited = true;
    int u = e->first == v ? e->second : e->first;
    if (color[u]) {
      detachable.push_back(*e);
    } else {
      color[u] = true;
      dfs(u, graph, color, detachable);
    }
  }
}

struct Model {
  int node;
  vector<Edge> edges;
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<ColorEdgePtr>> graph(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ColorEdge e({i, a - 1, b - 1}, false);
    ColorEdgePtr e_ptr = make_shared<ColorEdge>(e);
    graph[a - 1].push_back(e_ptr);
    graph[b - 1].push_back(e_ptr);
  }

  vector<bool> color(n, false);
  vector<Model> x;
  for (int i = 0; i < n; i++) {
    if (!color[i]) {
      color[i] = true;
      vector<Edge> detachable;
      dfs(i, graph, color, detachable);
      x.push_back({i, detachable});
    }
  }
  sort(x.begin(), x.end(), [](const Model &a, const Model &b) {
    return a.edges.size() > b.edges.size();
  });

  vector<Edge> y;
  for (auto &m : x) {
    for (auto e : m.edges) {
      y.push_back(e);
    }
  }

  int k = (int)x.size();
  cout << k - 1 << endl;
  for (int i = 1; i < k; i++) {
    int node = x[i].node;
    Edge &e = y[i - 1];
    cout << e.index + 1 << " " << e.second + 1 << " " << node + 1 << endl;
  }

  return 0;
}
