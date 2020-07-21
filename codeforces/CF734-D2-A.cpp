#include <bits/stdc++.h>
using namespace std;

int N;
string s;
int a = 0, d = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> s;
  for (auto c : s) {
    if (c == 'A')
      a++;
    if (c == 'D')
      d++;
  }
  if (a == d) {
    cout << "Friendship" << endl;
    return 0;
  }
  cout << (a > d ? "Anton" : "Danik") << endl;

  return 0;
}
