#include <bits/stdc++.h>
using namespace std;
int N, H, M, K;
map<int, vector<int>> m;
int ans = INT_MAX, ansS = 0, ansP = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> H >> M >> K;

  for (int i = 1, a, b; i <= N; i++) {
    cin >> a >> b;
    m[b % (M / 2)].push_back(i);
  }
  vector<int> v, cum = {0};
  int ct = 0;
  for (int i = 0; i < 2; i++) {
    for (auto p : m) {
      v.push_back(i * (M / 2) + p.first);
      ct += p.second.size();
      cum.push_back(ct);
    }
  }

  for (int i = 0; i < v.size() / 2; i++) {
    int pos = (int)(lower_bound(v.begin(), v.end(), v[i] + K) - v.begin());
    int s = cum[pos] - cum[i + 1];
    if (s < ans) {
      ans = s;
      ansS = i;
      ansP = pos;
    }
  }
  vector<int> ansV;
  for (int i = ansS + 1; i < ansP; i++) {
    for (auto x : m[v[i] % (M / 2)]) {
      ansV.push_back(x);
    }
  }
  cout << ans << " " << (v[ansS] + K) % (M / 2) << endl;
  if (ansV.size() >= 1)
    cout << ansV[0];
  for (int i = 1; i < ansV.size(); i++)
    cout << " " << ansV[i];
  cout << endl;
  return 0;
}
