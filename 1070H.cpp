#include <bits/stdc++.h>
using namespace std;

int N, Q;
string arr[10005];
map<string, set<int>> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    arr[i] = s;
    for (int a = 0; a < s.size(); a++) {
      for (int b = a; b < s.size(); b++) {
        m[s.substr(a, b - a + 1)].insert(i);
      }
    }
  }
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    string s;
    cin >> s;
    if (m.count(s) == 0) {
      cout << 0 << " "
           << "-" << endl;
    } else {
      cout << m[s].size() << " " << arr[*m[s].begin()] << endl;
    }
  }

  return 0;
}
