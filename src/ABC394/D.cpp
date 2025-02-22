#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  list<string> brs;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      brs.push_back("()");
      continue;
    }
    if (s[i] == '<') {
      brs.push_back("<>");
      continue;
    }
    if (s[i] == '[') {
      brs.push_back("[]");
      continue;
    }
    if (brs.begin() == brs.end()) {
      cout << "No" << endl;
      return 0;
    }
    if (s[i] == ')') {
      string type = *brs.rbegin();
      if (type == "()") {
        brs.pop_back();
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
    if (s[i] == '>') {
      string type = *brs.rbegin();
      if (type == "<>") {
        brs.pop_back();
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
    if (s[i] == ']') {
      string type = *brs.rbegin();
      if (type == "[]") {
        brs.pop_back();
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  if (brs.empty()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
