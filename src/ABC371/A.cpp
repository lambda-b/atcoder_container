#include <iostream>

using namespace std;

int main() {
  string sab;
  string sac;
  string sbc;

  cin >> sab;
  cin >> sac;
  cin >> sbc;

  if (sab == "<" && sac == ">") {
    cout << "A" << endl;
  }

  if (sab == "<" && sbc == "<") {
    cout << "B" << endl;
  }

  if (sab == ">" && sac == "<") {
    cout << "A" << endl;
  }

  if (sab == ">" && sbc == ">") {
    cout << "B" << endl;
  }

  if (sac == "<" && sbc == ">") {
    cout << "C" << endl;
  }

  if (sac == ">" && sbc == "<") {
    cout << "C" << endl;
  }
  return 0;
}
