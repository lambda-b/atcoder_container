#include <atcoder/all>
#include <iostream>

using namespace atcoder;
using namespace std;

int main() {
  int m;
  cin >> m;

  vector<int> a(0);
  int l = 0;
  do {
    int q = m % 3;
    for (int i = 0; i < q; i++) {
      a.push_back(l);
    }
    l++;
    m /= 3;
  } while (m != 0);

  cout << a.size() << endl;
  for (auto it = a.begin(); it != a.end(); it++) {
    if (it != a.begin()) {
      cout << " ";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
