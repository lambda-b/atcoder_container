#include <atcoder/all>
#include <iostream>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main() {
  int N;
  int M;

  cin >> N >> M;

  vector<int> A(M);
  vector<string> B(M);

  for (int i = 0; i < M; i++) {
    cin >> A[i];
    cin >> B[i];
  }

  vector<bool> C(N);
  vector<string> D(M, "No");

  for (int i = 0; i < M; i++) {
    if (B[i] == "M" && !C[A[i]]) {
      C[A[i]] = true;
      D[i] = "Yes";
    }
  }

  for (int i = 0; i < M; i++) {
    cout << D[i] << endl;
  }

  return 0;
}
