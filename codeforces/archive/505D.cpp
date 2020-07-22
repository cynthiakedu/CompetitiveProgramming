#include <bits/stdc++.h>
using namespace std;
int N, M;
int dsu1[100005], dsu2[100005];
int f1(int x) { return dsu1[x] == x ? x : dsu1[x] = f1(dsu1[x]); }
int f2(int x) { return dsu2[x] == x ? x : dsu2[x] = f2(dsu2[x]); }
vector<int> to[100005], from[100005];
int ans = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    dsu1[i] = i;
    dsu2[i] = i;
  }
  cin >> M;
  for (int i = 0, a, b; i < M; i++) {
    cin >> a >> b;
    if (a > b) {
      from[a].push_back(b);
    } else {
      to[b].push_back(a);
    }
  }
  for (int i = 1; i <= N; i++) {
    set<int> to1, from1;
    for (auto x : to[i]) {
      to1.insert(f1(x));
    }
    for (auto x : from[i]) {
      from1.insert(f2(x));
    }
    for (auto x : to1) {
      ans++;
      dsu1[x] = i;
    }
    for (auto x : from1) {
      ans++;
      dsu2[x] = i;
    }
  }
  cout << ans << endl;

  return 0;
}
