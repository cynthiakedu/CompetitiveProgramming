#include <bits/stdc++.h>
using namespace std;
int N, Q;

string s(string x) {
  if (x.size() == 1 || x.size() == 0) {
    return x;
  }
  string ret = "";
  string a = s(x.substr(0, (x.size() + 1) / 2));
  string b = s(x.substr((x.size() + 1) / 2, x.size() / 2));
  int idx1 = 0, idx2 = 0;
  while (idx1 != a.size() && idx2 != b.size()) {
    cout << "? " << a[idx1] << " " << b[idx2] << "\n";
    char ans;
    cin >> ans;
    if (ans == '<') {
      ret += a[idx1];
      idx1++;
    } else {
      ret += b[idx2];
      idx2++;
    }
  }
  if (idx1 < a.size()) {
    for (int i = idx1; i < a.size(); i++) {
      ret += a[i];
    }
  } else if (idx2 < b.size()) {
    for (int i = idx2; i < b.size(); i++) {
      ret += b[i];
    }
  }
  return ret;
}

int main() {
  cin >> N >> Q;

  string x = "";
  for (int i = 0; i < N; i++)
    x += (char)('A' + i);
  string ans = s(x);
  cout << "! " << ans << "\n";

  return 0;
}
