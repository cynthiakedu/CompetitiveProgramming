#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, m[1005];
ll ans = 0, ansV[1005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> m[i];

  for (int i = 0; i < N; i++) {
    ll temp[1005], ct = 0;
    temp[i] = m[i];
    for (int j = i - 1; j >= 0; j--) {
      temp[j] = min(temp[j + 1], m[j]);
    }
    for (int j = i + 1; j < N; j++) {
      temp[j] = min(temp[j - 1], m[j]);
    }
    for (int j = 0; j < N; j++) ct += temp[j];
    if (ct > ans) {
      ans = ct;
      for (int j = 0; j < N; j++) ansV[j] = temp[j];
    }
  }
  for (int i = 0; i < N; i++) cout << ansV[i] << (i == (N - 1) ? "\n" : " ");

  return 0;
}
