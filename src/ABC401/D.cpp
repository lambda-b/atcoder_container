#include <bits/stdc++.h>

#include <atcoder/all>
#include <boost/algorithm/string/replace.hpp>

#include "boost/algorithm/string/classification.hpp"
#include "boost/algorithm/string/split.hpp"

using namespace std;
using namespace atcoder;
using namespace boost::algorithm;

// 連続する？の中に最大いくつのoが入力できるかを考える
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int sm = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      if (i > 0 && s[i - 1] == 'o') {
        s[i] = '.';
      } else if (i < n - 1 && s[i + 1] == 'o') {
        s[i] = '.';
      }
    } else if (s[i] == 'o') {
      sm++;
    }
  }

  if (k == sm) {
    string rep = replace_all_copy(s, "?", ".");
    cout << rep << endl;
    return 0;
  }

  string rep1 = replace_all_copy("." + s + ".", ".?", ".,?");
  string rep2 = replace_all_copy(rep1, "?.", "?,.");
  vector<string> str_vec;
  split(str_vec, rep2, is_any_of(","));

  // o を入力できる最大値
  for (string &str : str_vec) {
    if (str[0] == '?') {
      int size = (int)str.size();
      sm += (size + 1) / 2;
    }
  }

  if (sm > k) {
    cout << s << endl;
    return 0;
  }

  string t = "";
  for (string &str : str_vec) {
    if (str[0] == '?') {
      int size = (int)str.size();
      if (size % 2 == 0) {
        t += str;
      } else {
        for (int i = 0; i < size / 2; i++) {
          t += "o.";
        }
        t += "o";
      }
    } else {
      t += str;
    }
  }

  string ans = t.substr(1, n);
  cout << ans << endl;

  return 0;
}
