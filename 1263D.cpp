#include <bits/stdc++.h>
using namespace std;
int N;
string arr[200005];
int p[200005];
int f(int x) { return p[x] == x ? x : p[x] = f(p[x]); }
int isSame(int x, int y) { return f(x) == f(y); }
map<int, set<int>> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    p[i] = i;
    string s;
    cin >> s;
    arr[i] = s;
  }

  for (int i = 1; i <= N; i++) {
    for (auto c : arr[i]) {
      m[c - 'a'].insert(i);
    }
  }

  for (int i = 0; i < 26; i++) {
    if (m[i].size() > 0) {
      int ele = *m[i].begin();
      for (auto x : m[i]) {
        if (!isSame(ele, x)) {
          p[f(ele)] = x;
        }
      }
    }
  }

  set<int> s;
  for (int i = 1; i <= N; i++) {
    s.insert(f(i));
  }
  cout << s.size() << endl;

  return 0;
}
