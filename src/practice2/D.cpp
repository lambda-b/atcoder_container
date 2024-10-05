#include <atcoder/all>
#include <iostream>
#include <limits>

using namespace atcoder;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int start = n * m;
  int end = n * m + 1;
  mf_graph<int> graph(n * m + 2);

  int limits = numeric_limits<int>::max();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        graph.add_edge(start, m * i + j, 1);
      } else {
        graph.add_edge(m * i + j, end, 1);
      }

      if (j == m) {
        break;
      }

      if (s[i][j] == '.' && s[i][j + 1] == '.') {
        int from = m * i + j;
        int to = m * i + j + 1;
        if ((i + j) % 2 == 1) {
          swap(from, to);
        }
        graph.add_edge(from, to, limits);
      }

      if (i == n - 1) {
        continue;
      }

      if (s[i][j] == '.' && s[i + 1][j] == '.') {
        int from = m * i + j;
        int to = m * (i + 1) + j;
        if ((i + j) % 2 == 1) {
          swap(from, to);
        }
        graph.add_edge(from, to, limits);
      }
    }
  }

  cout << graph.flow(start, end) << endl;

  auto edges = graph.edges();

  for (auto e = edges.begin(); e != edges.end(); e++) {
    int from = (*e).from;
    int to = (*e).to;
    int flow = (*e).flow;

    if (from == start || to == end || flow == 0) {
      continue;
    }

    int i_from = from / m;
    int j_from = from % m;

    int i_to = to / m;
    int j_to = to % m;

    if (i_from == i_to) {
      if (j_from < j_to) {
        s[i_from][j_from] = '>';
        s[i_to][j_to] = '<';
      } else {
        s[i_from][j_from] = '<';
        s[i_to][j_to] = '>';
      }
    }

    if (j_from == j_to) {
      if (i_from < i_to) {
        s[i_from][j_from] = 'v';
        s[i_to][j_to] = '^';
      } else {
        s[i_from][j_from] = '^';
        s[i_to][j_to] = 'v';
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << s[i] << endl;
  }

  return 0;
}
